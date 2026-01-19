package Main;
public class Client1 {

	public static void main(String[] args) {
		
		UsernameForm form = new UsernameForm();
		
		form.get("username").setData("tia");
		form.get("email").setData("tia@gmail.com");
		form.get("age").setData(16);
		form.validate();

		
		for (String err : form.errors)
			System.out.println(err);

		System.out.println(form.content());
		System.out.println(form.json());
	}

}
