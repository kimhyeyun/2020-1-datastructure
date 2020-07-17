#include<iostream>
using namespace std;

#define MappingSize 501

class vertex {
public:
	vertex* prev;
	vertex* next;
	int degree;
	int data; 

	vertex(int data) {
		this->data = data;
		this->degree = 0;
	}

	void increase_degree() {
		this->degree++;
	}

	void decrease_degree() {
		this->degree--;
	}
};

class edge {
public:
	edge* prev;
	edge* next;
	vertex* source;
	vertex* destination;
	string data;

	edge(vertex* a, vertex* b) {
		this->source = a;
		this->destination = b;
	}

	edge(vertex* a, vertex* b, string data) {
		this->source = a;
		this->destination = b;
		this->data = data;
	}
};

class DoublyVertexLinkedList {
public:
	vertex* head;
	vertex* tail;

	DoublyVertexLinkedList() {
		this->head = NULL;
		this->tail = NULL;
	}

	void insert(vertex* insertVertex) {
		if (this->head == NULL)
			head = tail = insertVertex;
		else {
			tail->next = insertVertex;
			insertVertex->prev = tail;
			tail = insertVertex;
		}
	}

	void remove(vertex* delVertex) {
		if (delVertex == head || delVertex == tail) {
			if (delVertex == head && delVertex != tail) {
				vertex* tmp = head;
				head = head->next;
				head->prev = NULL;
				delete tmp;
			}
			else if (delVertex == tail && delVertex != head) {
				vertex* tmp = tail;
				tail = tail->prev;
				tail->next = NULL;
				delete tmp;
			}
			else
				head = tail = NULL;
		}
		else {
			delVertex->prev->next = delVertex->next;
			delVertex->next->prev = delVertex->prev;
			delete delVertex;
		}
	}
};

class DoublyEdgeLinkedList {
public:
	edge* head;
	edge* tail;

	DoublyEdgeLinkedList() {
		this->head = NULL;
		this->tail = NULL;
	}

	void insert(edge* insertEdge) {
		if (this->head == NULL)
			head = tail = insertEdge;
		else {
			tail->next = insertEdge;
			insertEdge->prev = tail;
			tail = insertEdge;
		}
	}

	void remove(edge* delEdge) {
		if (delEdge == head || delEdge == tail) {
			if (delEdge == head && delEdge != tail) {
				edge* tmp = head;
				head = head->next;
				head->prev = NULL;
				delete tmp;
			}
			else if (delEdge == tail && delEdge != head) {
				edge* tmp = tail;
				tail = tail->prev;
				tail->next = NULL;
				delete tmp;
			}
			else
				head = tail = NULL;
		}
		else {
			delEdge->prev->next = delEdge->next;
			delEdge->next->prev = delEdge->prev;
			delete delEdge;
		}
	}
};

class graph {
public:
	edge*** edgeMatrix;
	DoublyVertexLinkedList* vertexList;
	DoublyEdgeLinkedList* edgeList;
	int vertexSize;
	int edgeSize;
	int mappingTable[MappingSize];

	graph() {
		this->vertexList = new DoublyVertexLinkedList();
		this->edgeList = new DoublyEdgeLinkedList();
		this->vertexSize = 0;
		this->edgeSize = 0;
		for (int i = 0; i < MappingSize; i++) mappingTable[i] = -1;
		this->edgeMatrix = new edge * *[1];
		this->edgeMatrix[0] = new edge * [1];
		this->edgeMatrix[0][0] = NULL;
	}

	bool isfindVertex(int n) {
		bool flag = false;
		vertex* tmp = vertexList->head;

		while (tmp != NULL) {
			if (tmp->data == n) {
				flag = true;
				break;
			}
			tmp = tmp->next;
		}
		return flag;
	}

	vertex* findVertex(int n) {
		vertex* tmp = vertexList->head;
		while (tmp != NULL) {
			if (tmp->data == n)
				break;
			tmp = tmp->next;
		}
		return tmp;
	}

	void insert_vertex(int n) {
		if (isfindVertex(n)==true)
			return;
		else {
			edge*** tmpMatrix = new edge * *[vertexSize + 1];
			
			for (int i = 0; i < vertexSize + 1; i++) {
				tmpMatrix[i] = new edge * [vertexSize + 1];
				for (int j = 0; j < vertexSize + 1; j++)
					tmpMatrix[i][j] = NULL;
			}

			for (int i = 0; i < vertexSize; i++) {
				for (int j = 0; j < vertexSize; j++)
					tmpMatrix[i][j] = this->edgeMatrix[i][j];
			}

			this->edgeMatrix = tmpMatrix;

			vertex* tmp = new vertex(n);
			vertexList->insert(tmp);
			this->vertexSize++;
			mappingTable[vertexSize - 1] = n;
		}
	}

	void erase_vertex(int n) {
		if (!isfindVertex(n) || this->vertexSize == 0) {
			cout << 0 << "\n";
			return;
		}
		else {
			edge*** tmpMatrix = new edge * *[vertexSize - 1];
			
			for (int i = 0; i < vertexSize - 1; i++) {
				tmpMatrix[i] = new edge * [vertexSize - 1];
				for (int j = 0; j < vertexSize - 1; j++)
					tmpMatrix[i][j] = NULL;
			}

			int middleIdx = 0;

			for (int i = 0; i < vertexSize; i++) {
				if (mappingTable[i] == n)
					middleIdx = i;
			}
			for (int i = middleIdx; i < vertexSize; i++) {
				mappingTable[i] = mappingTable[i + 1];
			}

			for (int i = 0; i < vertexSize; i++) {
				for (int j = 0; j < vertexSize; j++) {
					if (i < middleIdx && j < middleIdx)
						tmpMatrix[i][j] = this->edgeMatrix[i][j];
					else if (i > middleIdx && j > middleIdx)
						tmpMatrix[i - 1][j - 1] = this->edgeMatrix[i][j];
					else if (j > middleIdx)
						tmpMatrix[i][j - 1] = this->edgeMatrix[i][j];
					else if (i > middleIdx)
						tmpMatrix[i - 1][j] = this->edgeMatrix[i][j];
				}
			}

			this->edgeMatrix = tmpMatrix;
			vertexList->remove(findVertex(n));
			this->vertexSize--;
		}
	}

	void insert_edge(int Source, int Destination) {
		if (isfindVertex(Source) == false || isfindVertex(Destination) == false) {
			cout << -1 << "\n";
			return;
		}

		int destination = -1;
		int source = -1;

		for (int i = 0; i <= vertexSize; i++) {
			if (mappingTable[i] == Destination)
				destination = i;
			if (mappingTable[i] == Source)
				source = i;
			if (source != -1 && destination != -1)
				break;
		}

		if (edgeMatrix[source][destination] != NULL || edgeMatrix[destination][source] != NULL) {
			cout << -1 << '\n';
			return;
		}

		edge* newEdge = new edge(findVertex(Source), findVertex(Destination));
		edgeMatrix[source][destination] = newEdge;
		edgeMatrix[destination][source] = newEdge;

		findVertex(Source)->increase_degree();
		findVertex(Destination)->increase_degree();
		edgeSize++;
		edgeList->insert(newEdge);
	}

	void insert_edge(int Source, int Destination, string data) {
		if (isfindVertex(Source)==false || isfindVertex(Destination)==false) {
			cout << -1 << "\n";
			return;
		}

		int destination = -1;
		int source = -1;

		for (int i = 0; i <= vertexSize; i++) {
			if (mappingTable[i] == Source)
				source = i;
			if (mappingTable[i] == Destination)
				destination = i;
			if (source != -1 && destination != -1)
				break;
		}

		if (edgeMatrix[source][destination] != NULL || edgeMatrix[destination][source] != NULL) {
			cout << -1 << "\n";
			return;
		}

		edge* newEdge = new edge(findVertex(Source), findVertex(Destination), data);
		edgeMatrix[source][destination] = newEdge;
		edgeMatrix[destination][source] = newEdge;

		findVertex(Source)->increase_degree();
		findVertex(Destination)->increase_degree();
		edgeSize++;
		edgeList->insert(newEdge);
			
	}

	void erase_edge(int Source, int Destination) {
		int destination = -1;
		int source = -1;

		for (int i = 0; i <= vertexSize; i++) {
			if (mappingTable[i] == Source)
				source = i;
			if (mappingTable[i] == Destination)
				destination = i;
			if (source != -1 && destination != -1)
				break;
		}

		if (edgeMatrix[source][destination] == NULL || edgeMatrix[destination][source] == NULL) {
			return;
		}

		findVertex(Source)->decrease_degree();
		findVertex(Destination)->decrease_degree();

		edge* delEdge = edgeMatrix[source][destination];
		edgeList->remove(delEdge);

		edgeMatrix[source][destination] = NULL;
		edgeMatrix[destination][source] = NULL;
	}
};

int main() {
	graph gr;

	int N, M, I, S, D;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> I;
		gr.insert_vertex(I);
	}

	for (int i = 0; i < M; i++) {
		cin >> S >> D;
		gr.insert_edge(S, D);
	}

	cout <<gr.vertexSize<< " "<< gr.edgeSize << " \n";
}