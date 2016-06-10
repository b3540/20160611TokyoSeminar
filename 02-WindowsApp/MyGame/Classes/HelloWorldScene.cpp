#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// HelloWorld�V�[�����J�n���ꂽ�Ƃ��ŏ��Ɏ��s�����
bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    //��ʃT�C�Y���擾
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//�摜��ǂݍ���
	//�ǂݍ��މ摜��Resource�t�H���_�ɓ����Ă���
	auto sprite1 = Sprite::create("sampleimage.png");

	//�T�C�Y��ʒu�̎w��
	sprite1->setScale(0.2,0.2);
	sprite1->setPosition(visibleSize.width/2,visibleSize.height/2);
	

	//�^�b�`�C�x���g�̃��X�i�[���擾
	auto listener = EventListenerTouchOneByOne::create();
	//�^�b�`���J�n���ꂽ�Ƃ�
	listener->onTouchBegan = [](Touch* touch, Event* event) -> bool {
		return true;
	};
	//�^�b�`���I�������Ƃ�
	listener->onTouchEnded = [](Touch* touch, Event* event) -> bool {
		auto touchLocation = touch->getLocation();
		auto sprite = (Sprite*)event->getCurrentTarget();
		auto box = sprite->getBoundingBox();
		if (box.containsPoint(touchLocation)) {
			auto pos = sprite->getPosition();
			sprite->setPosition(pos.x+1,pos.y);
			sprite->setRotation(sprite->getRotation()+1);
		}
		return true;
	};
	
	//�^�b�`�C�x���g���X�i�[��o�^
	//�o�^��͉摜�ɓo�^����(�摜�ȊO�̏ꏊ�Ń^�b�`�C�x���g���������Ȃ�)
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, sprite1);
    
	//�摜���q�v�f�Ƃ��Ēǉ�
	this->addChild(sprite1, 0);

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
