// zig_packed_struct.zig
const std = @import("std");

const Flags = packed struct {
    a: u1,
    b: u1,
    c: u1,
    d: u1,
    _pad: u4 = 0,
};

pub fn main() !void {
    var f = Flags{ .a = 1, .b = 0, .c = 1, .d = 1 };
    const key: u8 = 0x5A;
    const enc: [9]u8 = comptime blk: {
        const plain = "ZIG-PLAY\n";
        var out: [plain.len]u8 = undefined;
        var i: usize = 0;
        while (i < plain.len) : (i += 1) out[i] = plain[i] ^ key;
        break :blk out;
    };

    var stdout = std.io.getStdOut().writer();
    try stdout.print("flags={x}\n", .{@bitCast(u8, f)});
    var buf: [enc.len]u8 = undefined;
    for (enc, 0..) |b, i| buf[i] = b ^ key;
    try stdout.print("{s}", .{buf});
}
