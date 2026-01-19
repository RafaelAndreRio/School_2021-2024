package Main;

import org.junit.Ignore;

@Ignore
public class Client2 {
	
	public static void main(String[] args) {
		
		UsernameForm form = new UsernameForm();
		form.get("username").setData("ti");
		form.get("email").setData("");
		form.get("age").setData(13);
		form.validate();
		
		for (String err : form.errors)
			System.out.println(err);
		
		System.out.println(form.content());
		System.out.println(form.json());
	}
}
