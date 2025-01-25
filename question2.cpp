#include <iostream>

struct Node{
	std::string name;
	int price;
	Node* next;

	Node(std::string name, int price){
		this->name = name;
		this->price = price;
		next = nullptr;
	}
};

class ToyBelts{
	public:
		Node* head1;
		Node* head2;

		ToyBelts(){
			head1 = nullptr;
			head2 = nullptr;
		};

		void printFrontBelt(Node* head){
			if(head == nullptr){
				std::cout<< "Head is null" << std::endl;
				return;
			}
			std::cout<< "First toy is " << head->name << ' ' << head->price << std::endl;
			return;
		}

		void printAllToys(Node* head){
			if(head == nullptr){
				std::cout<< "Head is null" << std::endl;
				return;
			}
			Node* cur = head;
			while(cur != nullptr){
				std::cout<< cur->name << ' ' << cur->price << std::endl;
				cur = cur->next;
			}
			return;
		}

		void AddToy(Node*& head, std::string name, int price){
			if(head == nullptr){
				head = new Node(name, price);
				return;
			}
			Node* cur = head;
			Node* temp = new Node(name, price);

			while(cur->next != nullptr){
				cur = cur->next; //moving forward
			}
			cur->next = temp;
			return;
		}

		void removeDefectAndCombine(Node*& head1, int a, int b, Node*& head2){

			if(a == 1){

			}
			else{
				
			}
			if(a>b || head1 == nullptr){
				return;
			}
			int counter = 1;
			//using sliding window?
			Node* left = head1;
			Node* right = head1;

			//move right first, then left
			while(counter < b){
				if(right == nullptr){
					return;
				}
				right = right->next;
				counter++;
			}
			counter = 1;
			//move left
			while(counter < a-1){ //1 RIGHT before the removal window!
				left = left->next;
				counter++;
			}

			// Node* deleteNode = left->next;
			// Node* temp;
			// while(deleteNode != right->next){
			// 	temp = deleteNode->next;
			// 	delete deleteNode;
			// 	deleteNode = temp;
			// }

			if(a == 1){
				head1 = right->next; //if the first item is removed, must move pointer
			}

			left->next = right->next; //removes the window, removal done, now need to combine.

			if(head2 == nullptr){
				return;
			}
			Node* cur = head1;
			while(cur->next != nullptr){
				cur = cur->next; //stop at the last node.
			}
			cur->next = head2;
			head2 = nullptr;
			return;
		}
};



int main(int argc, char* argv[]){


	ToyBelts* christmas = new ToyBelts;
	christmas->AddToy(christmas->head1, "Bear", 3);
	christmas->AddToy(christmas->head1, "Toy House", 5);
	christmas->AddToy(christmas->head1, "Coal", 2);
	christmas->AddToy(christmas->head1, "Sheep", 8);
	christmas->AddToy(christmas->head1, "Chicken", 2);
	christmas->printAllToys(christmas->head1);
	christmas->printFrontBelt(christmas->head1);

	std::cout<< std::endl;

	christmas->AddToy(christmas->head2, "Mask", 1);
	christmas->AddToy(christmas->head2, "Rock", 0);
	christmas->AddToy(christmas->head2, "Paper Airplane", 2);
	christmas->printAllToys(christmas->head2);
	christmas->printFrontBelt(christmas->head2);

	std::cout<< std::endl;

	christmas->removeDefectAndCombine(christmas->head1, 2, 3, christmas->head2);
	christmas->printAllToys(christmas->head1);

	return 0;
}