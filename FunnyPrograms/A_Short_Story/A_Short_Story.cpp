///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "vulkan/vulkan_first_example.h"
#include "vulkan/vulkan_hello_triangle.h"

using namespace std;

static void createAStory() noexcept

{
	cout << "Hello my friend! Welcome to my story!\n";
	cout << "King Athamus of northern Greece had two children's Phrixus and Helle．After he left his first wife and mar ried Ino，a wicked woman，the two children received all the cruel treatment that a stepmother could devise ，At one time the kingdom was ruined by a famine．" << endl;
	cout << "Would you like to help these children? y or n";
	char choice;
	cin >> choice;
	if ('y' == choice)
	{
		cout << "Ino persuaded her credulous husband into believingthat his son，Phrixus，was the actual cause of the disaster，and should be sacrificed to Zeus to endit．The poor boy was then placed on the altar and was about tobe knifed when a ram with goldenfleecewas sent down by thegods and carried off the two children on its back．" << endl;
		cout << " Do you want to know the ending? y or n";
		cin >> choice;
		if ('y' == choice)
		{
			cout << "As they flew over the strait that divides Asia from Europe，Helle，faint at the vast expanse of waterbelow ，fell into the sea and was drowned．Thus the sea of Helle，Hellespont，became the ancient name of the strip of water．Her brother kept on and arrived in Colchis on the eastern shore of the Black Sea．There he sacrificed the ram to Zeus and gave its golden fleece to King Aeetes，who nailed it on a sacred tree and put a sleepless dragon incharge ．" << endl;
		}
		else if ('n' == choice)
		{
			cout << "Oh No! The story ends." << endl;
		}
		else
		{
			cout << "Bad Choice!!" << endl;
		}
	}
	else if ('n' == choice)
	{
		cout << "Oh No! The story ends." << endl;
	}
	else
	{
		cout << "Bad Choice!!" << endl;
	}
}

int main() {

	// vulkanInitCase();

	int ret = 0;

	ret = FunnyPrograms::TzTriangleAppTestCase_01();

	return ret;
}