public class Booleantest {
  public static void main(String args[]) {
    Boolean a = new Boolean(true);
    System.out.println("a is " + a);
    Boolean b = new Boolean("true");
    Boolean c = new Boolean("OK");
    System.out.println("b is " + b);
    System.out.println("c is " + c);
    System.out.println("a.booleanValue() is " + a.booleanValue());
    System.out.println("a ?= b :" + a.equals(b));
  }
}
