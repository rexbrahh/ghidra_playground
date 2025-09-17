// rust_enum_trait.rs
trait Greeter {
    fn hello(&self) -> &'static str;
}
struct A;
struct B;
impl Greeter for A {
    fn hello(&self) -> &'static str {
        "A-OK"
    }
}
impl Greeter for B {
    fn hello(&self) -> &'static str {
        "B-SECRET"
    }
}

enum Mode {
    Add(i32, i32),
    Mul(i32, i32),
    Prize(Box<dyn Greeter>),
}

fn run(m: Mode) -> i32 {
    match m {
        Mode::Add(x, y) => x + y,
        Mode::Mul(x, y) => x * y,
        Mode::Prize(g) => {
            println!("{}", g.hello());
            1337
        }
    }
}

fn main() {
    let m = if std::env::args().nth(1) == Some("p".into()) {
        Mode::Prize(Box::new(B))
    } else {
        Mode::Mul(7, 6)
    };
    let r = run(m);
    println!("R={}", r);
}
