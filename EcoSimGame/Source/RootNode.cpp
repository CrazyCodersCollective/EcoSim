#include "RootNode.h"
#include <fstream>
//#include <streampos>
#include <iostream>
#include "json.hpp" 
#include "SpriteNode.h"
#include "ButtonNode.h"
RootNode::RootNode() {

}
RootNode::RootNode(PointerBag* pointerbag, int x, int y) //: Node.renderer(renderer), Node.x(x), Node.y(y), Node.screen(this), Node.master(this)
{
	if (renderer == NULL)printf("error in root node");
	this->renderer = renderer;
	this->master = this;
	this->screen = this;
	this->x = x;
	this->y = y;
}


RootNode::~RootNode()
{
}



RootNode* RootNode::Fromjson(const char* filepath) {

	RootNode* node = new RootNode();
	
	std::ifstream infile{ filepath };
	std::string file_contents{ std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>() };
	printf(file_contents.c_str());
	nlohmann::json j;
	try
	{
		j = nlohmann::json::parse(file_contents.c_str());
		ProssesJson(this, j);
	}
	catch (nlohmann::json::parse_error& e)
	{
		// output exception information
		std::cout << "message: " << e.what() << '\n'
			<< "exception id: " << e.id << '\n'
			<< "byte position of error: " << e.byte << std::endl;
	}
	

	

	return node;
}

void RootNode::ProssesJson(RootNode* node, nlohmann::json j)
{
	for (auto it = j.begin(); it != j.end(); ++it)
	{
		// the value
		//nlohmann::json &val = it.value();
		// the key (for objects)
		//const char* kc = it.key().c_str();
		std::string kc = it.key();
		if (kc == "name") {
			std::string ss = it.value();
			node->State = ss.c_str();
			printf(ss.c_str());
		}
		if (kc == "Nodes"){
			ProssesNodes(node, it.value());
		}
		//else printf("unknown key:%s\n", kc.c_str());

	}
}

void RootNode::ProssesNodes(Node* node, nlohmann::json j)
{
	for (auto it = j.begin(); it != j.end(); ++it)
	{
		// the value
		nlohmann::json &val = it.value();
		// the key (for objects)
		//const char* kc = it.key().c_str();
		std::string name = it.key();
		std::string kc = val["type"];
		if (kc == "Sprite")
			ProssesSprite(node, val);
		if (kc == "Button")
			ProssesButton(node, val);
		printf(kc.c_str());
	}
}

void RootNode::ProssesNode(Node* node, nlohmann::json j){

}
void RootNode::ProssesSprite(Node* node, nlohmann::json j) {

	Sprite* sp = new Sprite();
	node->AddChild(sp);
	for (auto it = j.begin(); it != j.end(); ++it)
	{
		
		// the value
		//nlohmann::json &val = it.value();
		// the key (for objects)
		//const char* kc = it.key().c_str();
		std::string kc = it.key();

		if (kc == "image")
			sp->Texture(it.value());
		if (kc == "pos")
			sp->SetPos(it.value()[0], it.value()[1]);
		if (kc == "children")
			ProssesNodes(sp, it.value());
	}
	nlohmann::json pos = j.value("pos", nlohmann::json::array({ 0,0 }));
	sp->SetPos(pos[0], pos[1]);
}

void RootNode::ProssesButton(Node* node, nlohmann::json j) {
	ButtonNode* butt = new ButtonNode();
	node->AddChild(butt);
	
	nlohmann::json pos = j.value("pos", nlohmann::json::array({10,10}));
	butt->SetPos(pos[0], pos[1]);
	
	nlohmann::json colour = j.value("bgTop", nlohmann::json::array({255,255,255,255}));
	butt->bgTop = SDL_Color{ colour[0],colour[1] ,colour[2] ,colour[3] };
	colour = j.value("bgBottom", nlohmann::json::array({ 240,240,240,255 }));
	butt->bgBottom = SDL_Color{ colour[0],colour[1] ,colour[2] ,colour[3] };


	//ProssesNodes(j.value("children", nlohmann::json::array()));
	//j.value("fontfile", "Resource/Fonts/monogram.ttf");
	//j.value("fontsize", 28);
	//j.value("padx", 28);
	//j.value("pady", 28);
	//j.value("borderWidth", 28);
	//j.value("borderRad", 28);
	//j.value("borderColour", 28);
	//j.value("textColor", 28);

	std::string text = j.value("text", "defult");
	if (text != "")
		butt->SetText(text);



	
}

