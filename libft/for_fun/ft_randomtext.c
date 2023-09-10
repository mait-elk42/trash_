#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char *getword()
{
    char *s[] = {
    "programming", "algorithm", "variable", "function", "debugging",
    "compiler", "software", "database", "encryption", "framework",
    "development", "version", "repository", "integration", "testing",
    "frontend", "backend", "middleware", "optimization", "security",
    "authentication", "encryption", "scripting", "framework", "interface",
    "serialization", "deserialization", "asynchronous", "synchronization", "multithreading",
    "virtualization", "cloud", "containerization", "agile", "scrum",
    "kanban", "code", "bug", "feature", "repository",
    "version", "control", "continuous", "integration", "deployment",
    "devops", "API", "web", "mobile", "desktop",
    "user", "interface", "UX", "UI", "responsive",
    "backend", "frontend", "full-stack", "HTTP", "HTTPS",
    "routing", "middleware", "session", "cookie", "authentication",
    "authorization", "token", "database", "SQL", "NoSQL",
    "ORM", "CRUD", "scalability", "performance", "caching",
    "load", "balancing", "microservices", "architecture", "containerization",
    "virtualization", "cloud", "serverless", "lambda", "deployment",
    "framework", "library", "package", "dependency", "package", "manager",
    "coding", "programming", "developer", "engineer", "software",
    "new stranger", "@newstrangerX", "API", "agile", "repository",
    "testing", "debugging", "containerization", "continuous", "integration",
    "frontend", "backend", "database", "encryption", "security",
    "algorithm", "optimization", "multithreading", "cloud", "authentication",
    "version", "repository", "middleware", "framework", "serialization",
    "deserialization", "encryption", "asynchronous", "synchronization", "scripting",
    "web", "mobile", "desktop", "user", "interface",
    "routing", "UX", "UI", "HTTP", "HTTPS",
    "session", "cookie", "authorization", "token", "NoSQL",
    "ORM", "CRUD", "scalability", "caching", "load",
    "balancing", "microservices", "architecture", "virtualization", "cloud",
    "serverless", "lambda", "deployment", "framework", "library",
    "package", "dependency", "package", "manager", "coding",
    "programming", "developer", "engineer", "software", "new stranger",
    "@newstrangerX", "API", "agile", "repository", "testing",
    "debugging", "containerization", "continuous", "integration", "frontend",
    "backend", "database", "encryption", "security", "algorithm",
    "optimization", "multithreading", "cloud", "authentication", "version",
    "repository", "middleware", "framework", "serialization", "deserialization",
    "encryption", "asynchronous", "synchronization", "scripting", "web",
    "mobile", "desktop", "user", "interface", "routing",
    "UX", "UI", "HTTP", "HTTPS", "session",
    "cookie", "authorization", "token", "NoSQL", "ORM",
    "CRUD", "scalability", "caching", "load", "balancing",
    "microservices", "architecture", "virtualization", "cloud", "serverless",
    "lambda", "deployment", "framework", "library", "package",
    "dependency", "package", "manager", "coding", "programming",
    "developer", "engineer", "software", "new stranger", "@newstrangerX","gamer", "hack", "cheat", "console", "controller",
    "online", "multiplayer", "leaderboard", "level", "score",
    "exploit", "cyber", "password", "firewall", "encryption",
    "virtual", "server", "virus", "software", "hardware",
    "FPS", "RPG", "LAN", "stream", "twitch",
    "griefing", "modding", "exploit", "script", "glitch",
    "hacker", "gaming", "noob", "pwned", "quest",
    "AI", "VR", "eSports", "guild", "mobile",
    "console", "respawn", "loot", "LAN", "ping",
    "character", "mmo", "NPC", "sandbox", "strategy",
    "patch", "cyberspace", "battle", "simulation", "scripting",
    "controller", "clan", "code", "hackathon", "programming",
    "mods", "MMORPG", "skins", "DLC", "headshot",
    "gamer tag", "exploit", "strategy", "trolling", "crack",
    "avatar", "cybersecurity", "speedrun", "bug", "sandbox",
    "unlock", "griefing", "glitch", "platform", "leaderboard",
    "LAN party", "firewall", "VR headset", "cosplay", "guild",
    "AI opponent", "online community", "server", "ping", "achievement",
    "eSports tournament", "mobile gaming", "virtual reality", "game over", "hacktivist",
    "cyberattack", "password reset", "game controller", "gaming console", "hacking group",
    "new stranger", "@newstrangerX"
};
    struct timespec ts;
    clock_gettime(0, &ts);
    srand((time_t)ts.tv_nsec);
    int i = rand() %  337;
    return s[i];
}
int ft_atoi(const char *s)
{
    int sign = 1;
    long r = 0;
    if(*s == '-' || *s == '+')
    {
        if(*s == '-')
            sign = -1;
        s++;
    }
    while(*s >= '0' && *s <= '9')
            r = (r *  10) - '0' + *s++;
    return r * sign;
}
int main(int ac,char *av[])
{
    int i = 0;
    if(ac == 2)
        while(i++ < ft_atoi(av[1]))
            printf("%s ",getword());
    printf("%s","\n");

}
