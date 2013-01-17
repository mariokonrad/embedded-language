f = function(player)
    print(player:race());
    player:action();
    print('');
end

players = {
    game.Ork(),
    game.Elf(),
    game.Dwarf(),
};

for p in pairs(players) do
    f(players[p]);
end
