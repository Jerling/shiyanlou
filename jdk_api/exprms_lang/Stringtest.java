public class Stringtest {
  public static void main(String args[]) {
    String s = new String("Java");
    String m = "java";
    System.out.println("The length of s is " + s.length());
    System.out.println("The length of m is " + s.length());
    System.out.println("equals test s and m : " + s.equals(m));
    System.out.println("equalsIgnoreCase test s and m : " + m.equalsIgnoreCase(s));
  }
}
