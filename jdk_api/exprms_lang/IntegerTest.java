public class IntegerTest {
  public static void main(String args[]) {
    Integer a = new Integer(10);
    Integer b = new Integer("15");
    System.out.println("byteValue: " + a.byteValue());
    System.out.println("a = " + a);
    System.out.println("b = " + b);

    System.out.println("a.compareTo(b): " + a.compareTo(b));
    System.out.println("a.equals(b): " + a.equals(b));

    float c = a.floatValue();
    System.out.println("float(a) : " + c);

    String d = "10101110";
    int e = Integer.parseInt(d, 2);
    System.out.println("10101110 = " + e);
  }
}
