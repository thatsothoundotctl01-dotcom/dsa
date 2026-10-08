 import java.util.ArrayList;
import java.util.List;

class Book {
    private String title;
    private String author;
    private String isbn;
    private boolean available = true;

    public Book(String title, String author, String isbn) {
        this.title = title;
        this.author = author;
        this.isbn = isbn;
    }

    public String getTitle()  { return title; }
    public String getAuthor() { return author; }
    public String getIsbn()   { return isbn; }
    public boolean isAvailable() { return available; }
    public void setAvailable(boolean available) { this.available = available; }

    @Override
    public String toString() {
        return title + " by " + author + " (ISBN: " + isbn + ") - "
               + (available ? "Available" : "Borrowed");
    }
}

class Member {
    private static final int MAX_BOOKS = 3;
    private String name;
    private int memberId;
    private List<Book> borrowedBooks = new ArrayList<>();

    public Member(String name, int memberId) {
        this.name = name;
        this.memberId = memberId;
    }

    public String getName() { return name; }
    public int getMemberId() { return memberId; }
    public List<Book> getBorrowedBooks() { return borrowedBooks; }

    public boolean canBorrow() { return borrowedBooks.size() < MAX_BOOKS; }
    public void addBook(Book b) { borrowedBooks.add(b); }
    public void removeBook(Book b) { borrowedBooks.remove(b); }
}

class Library {
    private List<Book> books = new ArrayList<>();
    private List<Member> members = new ArrayList<>();

    public void addBook(Book b) { books.add(b); }
    public void addMember(Member m) { members.add(m); }

    public boolean borrowBook(Member member, Book book) {
        if (!book.isAvailable()) {
            System.out.println("Book is already borrowed.");
            return false;
        }
        if (!member.canBorrow()) {
            System.out.println("Limit of 3 books reached.");
            return false;
        }
        book.setAvailable(false);
        member.addBook(book);
        return true;
    }

    public boolean returnBook(Member member, Book book) {
        if (!member.getBorrowedBooks().contains(book)) {
            System.out.println("This member did not borrow this book.");
            return false;
        }
        member.removeBook(book);
        book.setAvailable(true);
        return true;
    }

    public List<Book> searchByTitle(String keyword) {
        List<Book> result = new ArrayList<>();
        for (Book b : books) {
            if (b.getTitle().toLowerCase().contains(keyword.toLowerCase())) {
                result.add(b);
            }
        }
        return result;
    }

    public List<Book> searchByAuthor(String keyword) {
        List<Book> result = new ArrayList<>();
        for (Book b : books) {
            if (b.getAuthor().toLowerCase().contains(keyword.toLowerCase())) {
                result.add(b);
            }
        }
        return result;
    }
}

public class Main {
    public static void main(String[] args) {
        Library lib = new Library();
        Book b1 = new Book("Java Basics", "John", "111");
        Book b2 = new Book("OOP Design", "Mary", "222");
        lib.addBook(b1);
        lib.addBook(b2);

        Member m = new Member("Sok", 1);
        lib.addMember(m);

        lib.borrowBook(m, b1);
        System.out.println(b1);
        System.out.println(lib.searchByAuthor("mary"));
    }
}
