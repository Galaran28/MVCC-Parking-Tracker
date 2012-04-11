using namespace std;

class Car
{
public:
	Car(int);
	void SetEntrance(int);
	void SetDestination(int);
	int GetStatus();
	int GetEntrance();
	int GetDestination();
	~Car();

private:
	int status, entrance, destination;
};