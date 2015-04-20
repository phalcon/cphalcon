# Header {.h1}

## Header 2   {#h2}

### Header 3    {.h3 #h3}

header {.header #H2 .H1}
========================

header 2   {.header .H2 #H2}
--------

This is [an example](http://example.com/ "Title"){.example} inline link.

[This link](http://example.net/){#link} has no title attribute.

See my [About](/about/){#about .about} page for details.

This is the [simple case]{.example}

This is the [simple case]{#link}

This is the [simple case]{#about .abount}

This is the [simple case]{target="_blank"}

[simple case]: /simple

[link]

[link]{ .class-link }

[link]{ target="_blank" }

[link]: url "optional title" { #id .class }

* Red {.red}
* Green {.green}
* Blue  {.blue}

1. Bird {#bird .list .1}
2. McHale {#mchale .list .2}
3. Parish {#parish .list .3}

* Red {#1 .red}
    * Green {#2 .green}
        * Blue  {#3 .blue}

---

* Red {.red}
* Green {.green}
* Blue {.blue}
{@list .class-list .ul}

1. Bird {#bird .list .1}
2. McHale {#mchale .list .2}
3. Parish {#parish .list .3}
{@list .class-list .ol}

* Red {#1 .red}
{@list .class-list .level-1}
    * Green {#2 .green}
    {@list .class-list .level-2}
        * Blue  {#3 .blue}
        {@list .class-list .level-3}

---

1. Blah:

        $ ls test/{foo,bar}

---

Name    |  Age  {.table1}
--------|------
Fred    |   29
Jim     |   47
Harry   |   32

| Name    |  Age | {.table2 #tbl2}
|---------|-----:|
| Fred    |   29 |
| Jim     |   47 |
| Harry   |   32 |

```
code test
```

``` sh
code test
```

``` a b
code test
```

``` {.class-1}
code test
```

``` c {.class-2 #id-2}
code test
```

``` d{#id-3 .class-3 .class-4}
code test
```

``` {#id-5 .class-5}
code test
```
