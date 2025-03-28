#include <vector>
#include <string>
#include <stack>

using namespace std; 

class TextEditor {
private:
    string currentText;
    stack<pair<string, bool>> history;  //use to store the previous state and operation type
    
    //helper to process the insert operation
    void handleInsert(const string& text) {
        //store prev state for event of a potential undo
        if (!text.empty()) {
            history.push({currentText, true});  //true indicates successful operation
            currentText += text;
        }
    }
    
    //helper method to process BACKSPACE operation
    void handleBackspace() {
        if (!currentText.empty()) {
            history.push({currentText, true});  //true indicates successful operation
            currentText.pop_back();
        }
    }
    
    //helper method to process UNDO operation
    void handleUndo() {
        if (!history.empty()) {
            auto lastOperation = history.top();
            if (lastOperation.second) {  //if it was a successful operation
                currentText = lastOperation.first;
                history.pop();
            }
        }
    }
    
    //helper method to parse INSERT command
    string parseInsertCommand(const string& operation) {
        return operation.substr(7);  //skkip "INSERT "
    }

public:
    vector<string> processOperations(const vector<string>& operations) {
        vector<string> results;
        currentText = "";
        
        for (const string& operation : operations) {
            if (operation.substr(0, 6) == "INSERT") 
                handleInsert(parseInsertCommand(operation));
            
            else if (operation == "BACKSPACE") 
                handleBackspace();
            
            else if (operation == "UNDO") 
                handleUndo();
            
            
            results.push_back(currentText);
        }
        
        return results;
    }
};

vector<string> solution(vector<string> operations) {
    TextEditor editor;
    return editor.processOperations(operations);
}