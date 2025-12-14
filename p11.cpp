#include<iostream>  // Include input/output library
#include<string>    // Include string library
using namespace std; // Use standard namespace

// Define a record structure for hash table
struct Rec{
    int key;       // Store key
    string name;   // Store name
    bool used=false; // Flag to check if slot is used
};

int main(){
    int m,n;
    cout<<"Enter size of hash table: "; // Ask for hash table size
    cin>>m;                              // Read hash table size

    Rec HT[100];                          // Create array of 100 records

    cout<<"Enter number of records: ";    // Ask how many records to insert
    cin>>n;                               // Read number of records

    for(int i=0;i<n;i++){                 // Loop to insert each record
        int k;
        string name;
        cout<<"Enter key: ";              // Ask for key
        cin>>k;                           // Read key
        cout<<"Enter name: ";             // Ask for name
        cin>>name;                        // Read name

        int index = k % m;                // Calculate hash index

        while(HT[index].used){            // If slot is used, find next free slot
            index = (index + 1) % m;     // Linear probing
        }

        HT[index].key = k;                // Store key
        HT[index].name = name;            // Store name
        HT[index].used = true;            // Mark slot as used
        cout<<"Stored at index "<<index<<endl; // Show where record is stored
    }

    cout<<"Hash Table contents:"<<endl;   // Display hash table
    for(int i=0;i<m;i++){                 // Loop through hash table
        if(HT[i].used){                   // If slot is used
            cout<<HT[i].key<<":"<<HT[i].name<<endl; // Print key:name
        }else{
            cout<<i<<" Empty"<<endl;      // If slot empty, print empty
        }
    }

    int s;
    cout<<"Enter key to search: ";        // Ask for key to search
    cin>>s;                               // Read search key

    int index = s % m, start=index;       // Calculate start index
    while(HT[index].used){                // Search until empty slot
        if(HT[index].key == s){           // If key matches
            cout<<"Found at index "<<index<<":"<<HT[index].name<<endl; // Found!
            return 0;                     // Exit program
        }
        index = (index + 1) % m;          // Linear probing to next index
        if(index == start){                // If back to start, stop
           break;
        }
    }
    cout<<"Not found"<<endl;              // Key not found
}
