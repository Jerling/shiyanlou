public class Charactertest {
  public static void main(String args[]) {
    int count;
    char[] values = {'*', '_', '%', '8', 'L', 'l', ' '};
    for (count = 0; count < values.length; count++) {
      if (Character.isDigit(values[count])) {
        System.out.println(values[count] + " is a digit");
      }
      if (Character.isLetter(values[count])) {
        System.out.println(values[count] + " is a letter");
      }
      if (Character.isUpperCase(values[count])) {
        System.out.println(values[count] + " is a upperletter");
      }
      if (Character.isLowerCase(values[count])) {
        System.out.println(values[count] + " is a lowerletter");
      }
      if (Character.isUnicodeIdentifierStart(values[count])) {
        System.out.println(values[count] + " is a first sign of unicode");
      }
      if (Character.isWhitespace(values[count])) {
        System.out.println(values[count] + " is a whitespace"); 
      }
    }
  }
}
