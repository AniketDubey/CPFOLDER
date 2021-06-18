import 'dart:async';

main() {
  print("Main program STARTS");
  printFileContent();
  print("Main program ENDS");
  print("Main program ENDS");
  print("Main program ENDS");
  print("Main program ENDS");
  print("Main program ENDS");
  print("Main program ENDS");
  print("Main program ENDS");
  print("Main program ENDS");
  print("Main program ENDS");
  print("Main program ENDS");
  print("Main program ENDS");
}

printFileContent() async {
  /*String filecontent =
      await downloadFile(); // now this will return a valid result with no FUTURE CLASS involved
  print("the constent of the file is --> $filecontent");*/

  // one more way is that USING THEN FUNCTION

  Future<String> filecontent = downloadFile();
  filecontent.then((resultString) {
    print("the constent of the file is --> $resultString");
  });
}

Future<String> downloadFile() {
  Future<String> result = Future.delayed(Duration(microseconds: -1), () {
    // this will returna  future object but after 6 seconds that future object will convert to a string with the following result value
    return ("My secrent file content");
  });

  return result;
}
