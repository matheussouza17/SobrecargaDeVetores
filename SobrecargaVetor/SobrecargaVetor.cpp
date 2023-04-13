#include "Vetor.h"

int main()
{
    cout << "Digite o tamanho dos vetores: ";
    int n = 0;
    cin >> n;

    Vetor A(n);
    Vetor B(n);

    cout << "Prencha o vetor A: ";
    cin >> A;
    cout << "Prencha o vetor B: ";
    cin >> B;
    

    cout << "Tamanho de A: " << A.getSize() << endl;
    cout << "Vetor A: " << A<<endl;
    cout << "Tamanho de B: " << B.getSize() << endl;
    cout << "Vetor B: " << B<<endl;

    if (A != B)
        cout << "A e B diferentes." << endl << endl;

    //A[15]=10;
    //cout << "A[15]=" << A[15] << endl;

    cout << "Soma:\nA + B = " << A + B << endl;
    cout << "Subtracao:\nA - B = " << A - B << endl;
    cout << "O produto escalar:\nA*B = " << A * B;

    return 0;
}
