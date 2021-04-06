# 1) Account
Create an account on [GitHub](http://github.com) and email the account name to `{mario.stanke,irrgang}@uni-greifswald.de` (both).

# 2) Basic git usage
Create your own repository, e.g. with name `ownProject`, and perform steps 1) - 7) of
https://github.com/MarioStanke/git-workflows/blob/master/README.md :
 - create repository
 - `git add`, `git status`, `git commit`
 - `.gitignore`
 - `git branch`, `git checkout`
 - `git merge`, `git log`
 - `git push`, `git pull`

# 3) Pull request
*Clone* the repository `pst19-spielplatz`
```
git clone https://github.com/mslehre/pst19-spielplatz.git
```
Add a new command-line parameter to `exercise1/do.cc` as assigned to you from the following table

| key | parameter                           |
|-----|:------------------------------------|
| a   | an unsigned integer `numthreads`    |
| b   | a string `name`                     |
| c   | a double `threshold`                |
| d   | an int `x-offset`                   |
| e   | an int `y-offset`                   |
| f   | a boolean flag `verbose`            |
| g   | a boolean flag `help`               |
| h   | a character `sex`                   |


For this, follow the following steps:
 1. Pull the latest commit from `master` with `git pull`.
 2. create a branch `feature/x` where `x` is your one-letter key from above list (`git branch`, `git checkout`, `git push`).
 3. Implement above feature in the same style and let `main` print out the result of
    the passed argument. Test it.
 4. Commit your changes locally (`git add`, `git status`, `git commit`).
 5. Bring the changes that were made remotely by others up to date in your local repository with:
    ```
    git fetch
    ```
 6. Merge the changes of others on the master branch with your changes:
    ```
    git merge origin/master
    ```
    and resolve conflicts, if any.
 7. In the meantime you should have been granted pushing rights to this repository.
    Push your changes to GitHub: `git push origin feature/x`  
 8. Make a pull request on GitHub on your feature branch and await the message was it was granted or whether there were requests for changes.
 

# 4) Markdown
Install a Markdown viewer browser extension or another Markdown viewer.
In your own repository, create a file `README.md` at the top-level with
 - an example of code typeset in fixed font
 - an image
 - a LATeX formula.
 
