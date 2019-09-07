---
layout: default
language: 'en'
version: '4.0'
title: 'Phalcon\Html'
---

* [Phalcon\Html\Attributes](#html-attributes)
* [Phalcon\Html\Attributes\AttributesInterface](#html-attributes-attributesinterface)
* [Phalcon\Html\Attributes\RenderInterface](#html-attributes-renderinterface)
* [Phalcon\Html\Breadcrumbs](#html-breadcrumbs)
* [Phalcon\Html\Exception](#html-exception)
* [Phalcon\Html\Helper\AbstractHelper](#html-helper-abstracthelper)
* [Phalcon\Html\Helper\Anchor](#html-helper-anchor)
* [Phalcon\Html\Helper\AnchorRaw](#html-helper-anchorraw)
* [Phalcon\Html\Helper\Body](#html-helper-body)
* [Phalcon\Html\Helper\Button](#html-helper-button)
* [Phalcon\Html\Helper\Close](#html-helper-close)
* [Phalcon\Html\Helper\Element](#html-helper-element)
* [Phalcon\Html\Helper\ElementRaw](#html-helper-elementraw)
* [Phalcon\Html\Helper\Form](#html-helper-form)
* [Phalcon\Html\Helper\Img](#html-helper-img)
* [Phalcon\Html\Helper\Label](#html-helper-label)
* [Phalcon\Html\Helper\TextArea](#html-helper-textarea)
* [Phalcon\Html\Tag](#html-tag)
* [Phalcon\Html\TagFactory](#html-tagfactory)
        
<h1 id="html-attributes">Class Phalcon\Html\Attributes</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/html/attributes.zep)

| Namespace  | Phalcon\Html |
| Uses       | Phalcon\Collection, Phalcon\Html\Attributes\RenderInterface, Phalcon\Tag |
| Extends    | Collection |
| Implements | RenderInterface |

This class helps to work with HTML Attributes


## Methods
```php
public function __toString(): string;
```
Alias of the render method


```php
public function render(): string;
```
Render attributes as HTML attributes



        
<h1 id="html-attributes-attributesinterface">Interface Phalcon\Html\Attributes\AttributesInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/html/attributes/attributesinterface.zep)

| Namespace  | Phalcon\Html\Attributes |
| Uses       | Phalcon\Html\Attributes |

* Phalcon\Html\Attributes\AttributesInterface
*
* Interface Phalcon\Html\Attributes\AttributesInterface
*/

## Methods
```php
public function getAttributes(): Attributes;
```
Get Attributes


```php
public function setAttributes( Attributes $attributes ): AttributesInterface;
```
Set Attributes



        
<h1 id="html-attributes-renderinterface">Interface Phalcon\Html\Attributes\RenderInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/html/attributes/renderinterface.zep)

| Namespace  | Phalcon\Html\Attributes |

* Phalcon\Html\Attributes\RenderInterface
*
* Interface Phalcon\Html\Attributes\RenderInterface
*/

## Methods
```php
public function render(): string;
```
Generate a string represetation



        
<h1 id="html-breadcrumbs">Class Phalcon\Html\Breadcrumbs</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/html/breadcrumbs.zep)

| Namespace  | Phalcon\Html |
| Uses       | Phalcon\Di\DiInterface |

Phalcon\Html\Breadcrumbs

This component offers an easy way to create breadcrumbs for your application.
The resulting HTML when calling `render()` will have each breadcrumb enclosed
in `<dt>` tags, while the whole string is enclosed in `<dl>` tags.


## Properties
```php
/**
 * Keeps all the breadcrumbs
 *
 * @var array
 */
private elements;

/**
 * Crumb separator
 *
 * @var string
 */
private separator =  / ;

/**
 * The HTML template to use to render the breadcrumbs.
 *
 * @var string
 */
private template = <dt><a href=\"%link%\">%label%</a></dt>;

```

## Methods
```php
public function add( string $label, string $link = string ): Breadcrumbs;
```
Adds a new crumb.

```php
// Adding a crumb with a link
$breadcrumbs->add("Home", "/");

// Adding a crumb without a link (normally the last one)
$breadcrumbs->add("Users");
```


```php
public function clear(): void;
```
Clears the crumbs

```php
$breadcrumbs->clear()
```


```php
public function getSeparator(): string
```


```php
public function remove( string $link ): void;
```
Removes crumb by url.

```php
$breadcrumbs->remove("/admin/user/create");

// remove a crumb without an url (last link)
$breadcrumbs->remove();
```


```php
public function render(): string;
```
Renders and outputs breadcrumbs based on previously set template.

```php
echo $breadcrumbs->render();
```


```php
public function setSeparator( string $separator )
```


```php
public function toArray(): array;
```
Returns the internal breadcrumbs array



        
<h1 id="html-exception">Class Phalcon\Html\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/html/exception.zep)

| Namespace  | Phalcon\Html |
| Extends    | \Phalcon\Exception |

Phalcon\Html\Tag\Exception

Exceptions thrown in Phalcon\Html\Tag will use this class


        
<h1 id="html-helper-abstracthelper">Abstract Class Phalcon\Html\Helper\AbstractHelper</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/html/helper/abstracthelper.zep)

| Namespace  | Phalcon\Html\Helper |
| Uses       | Phalcon\Html\Exception, Phalcon\Escaper\EscaperInterface |

Phalcon\Html\Helper\AbstractHelper

Abstract class for all html helpers


## Properties
```php
/**
 * @var <EscaperInterface>
 */
protected escaper;

```

## Methods
```php
public function __construct( EscaperInterface $escaper );
```
Constructor


```php
protected function orderAttributes( array $overrides, array $attributes ): array;
```
Keeps all the attributes sorted - same order all the tome

@param array overrides
@param array attributes

@return array


```php
protected function renderAttributes( array $attributes ): string;
```
Renders all the attributes


```php
protected function renderElement( string $tag, array $attributes = [] ): string;
```
Renders an element


```php
protected function renderFullElement( string $tag, string $text, array $attributes = [], bool $raw = bool ): string;
```
Renders an element


```php
protected function selfClose( string $tag, array $attributes = [] ): string;
```
Produces a self close tag i.e. <img />



        
<h1 id="html-helper-anchor">Class Phalcon\Html\Helper\Anchor</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/html/helper/anchor.zep)

| Namespace  | Phalcon\Html\Helper |
| Uses       | Phalcon\Html\Helper\AbstractHelper |
| Extends    | AbstractHelper |

Phalcon\Html\Helper\Anchor

Creates an anchor


## Methods
```php
public function __invoke( string $href, string $text, array $attributes = [] ): string;
```
@var string href       The href tag
@var string text       The text for the anchor
@var array  attributes Any additional attributes



        
<h1 id="html-helper-anchorraw">Class Phalcon\Html\Helper\AnchorRaw</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/html/helper/anchorraw.zep)

| Namespace  | Phalcon\Html\Helper |
| Uses       | Phalcon\Html\Helper\AbstractHelper |
| Extends    | AbstractHelper |

Phalcon\Html\Helper\AnchorRaw

Creates a raw anchor


## Methods
```php
public function __invoke( string $href, string $text, array $attributes = [] ): string;
```
@var string href       The href tag
@var string text       The text for the anchor
@var array  attributes Any additional attributes



        
<h1 id="html-helper-body">Class Phalcon\Html\Helper\Body</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/html/helper/body.zep)

| Namespace  | Phalcon\Html\Helper |
| Uses       | Phalcon\Html\Helper\AbstractHelper |
| Extends    | AbstractHelper |

Phalcon\Html\Helper\Body

Creates a body tag


## Methods
```php
public function __invoke( array $attributes = [] ): string;
```
@var array  attributes Any additional attributes



        
<h1 id="html-helper-button">Class Phalcon\Html\Helper\Button</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/html/helper/button.zep)

| Namespace  | Phalcon\Html\Helper |
| Uses       | Phalcon\Html\Helper\AbstractHelper |
| Extends    | AbstractHelper |

Phalcon\Html\Helper\Button

Creates a button tag


## Methods
```php
public function __invoke( string $text, array $attributes = [] ): string;
```
@var string text       The text for the anchor
@var array  attributes Any additional attributes



        
<h1 id="html-helper-close">Class Phalcon\Html\Helper\Close</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/html/helper/close.zep)

| Namespace  | Phalcon\Html\Helper |
| Extends    | AbstractHelper |

Phalcon\Html\Helper\Close

Creates a closing tag


## Methods
```php
public function __invoke( string $tag ): string;
```
@param string $tag The tag

@return string



        
<h1 id="html-helper-element">Class Phalcon\Html\Helper\Element</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/html/helper/element.zep)

| Namespace  | Phalcon\Html\Helper |
| Uses       | Phalcon\Html\Helper\AbstractHelper |
| Extends    | AbstractHelper |

Phalcon\Html\Helper\Address

Creates an element


## Methods
```php
public function __invoke( string $tag, string $text, array $attributes = [] ): string;
```
@var string tag        The tag name
@var string text       The text for the anchor
@var array  attributes Any additional attributes



        
<h1 id="html-helper-elementraw">Class Phalcon\Html\Helper\ElementRaw</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/html/helper/elementraw.zep)

| Namespace  | Phalcon\Html\Helper |
| Uses       | Phalcon\Html\Exception |
| Extends    | AbstractHelper |

Phalcon\Html\Helper\ElementRaw

Creates an element raw


## Methods
```php
public function __invoke( string $tag, string $text, array $attributes = [] ): string;
```
@param string $tag        The tag for the anchor
@param string $text       The text for the anchor
@param array  $attributes Any additional attributes

@return string
@throws Exception



        
<h1 id="html-helper-form">Class Phalcon\Html\Helper\Form</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/html/helper/form.zep)

| Namespace  | Phalcon\Html\Helper |
| Uses       | Phalcon\Html\Helper\AbstractHelper |
| Extends    | AbstractHelper |

Phalcon\Html\Helper\Form

Creates a form opening tag


## Methods
```php
public function __invoke( array $attributes = [] ): string;
```
@var array  attributes Any additional attributes



        
<h1 id="html-helper-img">Class Phalcon\Html\Helper\Img</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/html/helper/img.zep)

| Namespace  | Phalcon\Html\Helper |
| Uses       | Phalcon\Html\Exception |
| Extends    | AbstractHelper |

Phalcon\Html\Helper\Img

Creates am img tag


## Methods
```php
public function __invoke( string $src, array $attributes = [] ): string;
```
@param string $src
@param array  $attributes Any additional attributes

@return string
@throws Exception



        
<h1 id="html-helper-label">Class Phalcon\Html\Helper\Label</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/html/helper/label.zep)

| Namespace  | Phalcon\Html\Helper |
| Uses       | Phalcon\Html\Exception |
| Extends    | AbstractHelper |

Phalcon\Html\Helper\Label

Creates a label


## Methods
```php
public function __invoke( array $attributes = [] ): string;
```
@param array $attributes Any additional attributes

@return string
@throws Exception



        
<h1 id="html-helper-textarea">Class Phalcon\Html\Helper\TextArea</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/html/helper/textarea.zep)

| Namespace  | Phalcon\Html\Helper |
| Uses       | Phalcon\Html\Helper\AbstractHelper |
| Extends    | AbstractHelper |

Phalcon\Html\Helper\TextArea

Creates a textarea tag


## Methods
```php
public function __invoke( string $text, array $attributes = [] ): string;
```
@var string text       The text for the anchor
@var array  attributes Any additional attributes



        
<h1 id="html-tag">Class Phalcon\Html\Tag</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/html/tag.zep)

| Namespace  | Phalcon\Html |
| Uses       | Phalcon\Di\DiInterface, Phalcon\Di\AbstractInjectionAware, Phalcon\Escaper, Phalcon\Escaper\EscaperInterface, Phalcon\Helper\Arr, Phalcon\Html\Exception, Phalcon\Url\UrlInterface, Phalcon\Mvc\Model\ResultsetInterface |
| Extends    | AbstractInjectionAware |

Phalcon\Html\Tag

Phalcon\Html\Tag is designed to simplify building of HTML tags. It provides a
set of helpers to dynamically generate HTML.


## Constants
```php
const HTML32 = 1;
const HTML401_FRAMESET = 4;
const HTML401_STRICT = 2;
const HTML401_TRANSITIONAL = 3;
const HTML5 = 5;
const XHTML10_FRAMESET = 8;
const XHTML10_STRICT = 6;
const XHTML10_TRANSITIONAL = 7;
const XHTML11 = 9;
const XHTML20 = 10;
const XHTML5 = 11;
```

## Properties
```php
/**
 * @var array
 */
private append;

/**
 * @var int
 */
private docType = 5;

/**
 * @var <EscaperInterface>
 */
private escaper;

/**
 * @var array
 */
private prepend;

/**
 * @var string
 */
private separator = ;

/**
 * @var string
 */
private title = ;

/**
 * @var array
 */
private values;

/**
 * @var <UrlInterface>
 */
private url;

```

## Methods
```php
public function __construct( EscaperInterface $escaper = null, UrlInterface $url = null );
```
Constructor


```php
public function appendTitle( mixed $title ): Tag;
```
Appends a text to current document title


```php
public function button( string $name, array $parameters = [] ): string;
```
Builds a HTML input[type="button"] tag

```php
use Phalcon\Html\Tag;

$tag = new Tag();

echo $tag->button('Click Me');
```

Volt syntax:
```php
{% raw %}{{ button('Click Me') }}{% endraw %}
```


```php
public function clear(): void;
```
Resets the request and internal values to avoid those fields will have
any default value.


```php
public function element( string $tag, array $parameters = [] ): string;
```
Builds a HTML tag

Parameters
`onlyStart` Only process the start of th element
`selfClose` It is a self close element
`useEol`    Append PHP_EOL at the end


```php
public function elementClose( string $tag, array $parameters = [] ): string;
```
Builds the closing tag of an html element

Parameters
`useEol`    Append PHP_EOL at the end

```php
use Phalcon\Html\Tag;

$tab = new Tag();

echo $tag->elementClose(
    [
        'name' => 'aside',
    ]
); // </aside>

echo $tag->elementClose(
    [
        'name'   => 'aside',
        'useEol' => true,
    ]
); // '</aside>' . PHP_EOL
```


```php
public function endForm( bool $eol = bool ): string;
```
Returns the closing tag of a form element


```php
public function form( string $action, array $parameters = [] ): string;
```
Builds a HTML FORM tag

```php
use Phalcon\Html\Tag;

$tab = new Tag();

echo $tag->form('posts/save');

echo $tag->form(
    'posts/save',
    [
        "method" => "post",
    ]
);
```

Volt syntax:
```php
{% raw %}{{ form('posts/save') }}{% endraw %}
{% raw %}{{ form('posts/save', ['method': 'post') }}{% endraw %}
```


```php
public function friendlyTitle( string $text, array $parameters = [] ): string;
```
Converts text to URL-friendly strings

Parameters
`text`      The text to be processed
`separator` Separator to use (default '-')
`lowercase` Convert to lowercase
`replace`

```php
use Phalcon\Html\Tag;

$tab = new Tag();

echo $tag->friendlyTitle(
    [
        'text'       => 'These are big important news',
        'separator' => '-',
    ]
);
```

Volt Syntax:
```php
{% raw %}{{ friendly_title(['text': 'These are big important news', 'separator': '-']) }}{% endraw %}
```


```php
public function getDocType(): string;
```
Get the document type declaration of content. If the docType has not
been set properly, XHTML5 is returned


```php
public function getTitle( bool $prepend = bool, bool $append = bool ): string;
```
Gets the current document title. The title will be automatically escaped.

```php
use Phalcon\Html\Tag;

$tag = new Tag();

$tag
       ->setTitleSeparator(' ')
        ->prependTitle(['Hello'])
        ->setTitle('World')
        ->appendTitle(['from Phalcon']);

echo $tag->getTitle();             // Hello World from Phalcon
echo $tag->getTitle(false);        // World from Phalcon
echo $tag->getTitle(true, false);  // Hello World
echo $tag->getTitle(false, false); // World
```

Volt syntax:
```php
{% raw %}{{ get_title() }}{% endraw %}
```


```php
public function getTitleSeparator(): string;
```
Gets the current document title separator

```php
use Phalcon\Html\Tag;

$tag = new Tag();

echo $tag->getTitleSeparator();
```

Volt syntax:
```php
{% raw %}{{ get_title_separator() }}{% endraw %}
```


```php
public function getValue( string $name, array $parameters = [] ): mixed | null;
```
Every helper calls this function to check whether a component has a
predefined value using `setAttribute` or value from $_POST


```php
public function hasValue( string $name ): bool;
```
Check if a helper has a default value set using `setAttribute()` or
value from $_POST


```php
public function image( string $url = string, array $parameters = [] ): string;
```
Builds HTML IMG tags

Parameters
`local` Local resource or not (default `true`)

```php
use Phalcon\Html\Tag;

$tag = new Tag();

echo $tag->image('img/bg.png');

echo $tag->image(
    'img/photo.jpg',
    [
        'alt' => 'Some Photo',
    ]
);

echo $tag->image(
    'http://static.mywebsite.com/img/bg.png',
    [
        'local' => false,
    ]
);
```

Volt Syntax:
```php
{% raw %}{{ image('img/bg.png') }}{% endraw %}
{% raw %}{{ image('img/photo.jpg', ['alt': 'Some Photo') }}{% endraw %}
{% raw %}{{ image('http://static.mywebsite.com/img/bg.png', ['local': false]) }}{% endraw %}
```


```php
public function inputCheckbox( string $name, array $parameters = [] ): string;
```
Builds a HTML input[type="check"] tag

```php
echo $tag->inputCheckbox(
    [
        'name'  => 'terms,
        'value' => 'Y',
    ]
);
```

Volt syntax:
```php
{% raw %}{{ input_checkbox(['name': 'terms, 'value': 'Y']) }}{% endraw %}
```


```php
public function inputColor( string $name, array $parameters = [] ): string;
```
Builds a HTML input[type='color'] tag


```php
public function inputDate( string $name, array $parameters = [] ): string;
```
Builds a HTML input[type='date'] tag

```php
use Phalcon\Html\Tag;

$tag = new Tag();

echo $tag->inputDate(
    [
        'name'  => 'born',
        'value' => '14-12-1980',
    ]
);
```

Volt syntax:
```php
{% raw %}{{ input_date(['name':'born', 'value':'14-12-1980']) }}{% endraw %}
```


```php
public function inputDateTime( string $name, array $parameters = [] ): string;
```
   Builds a HTML input[type='datetime'] tag
   
```php
use Phalcon\Html\Tag;

$tag = new Tag();

echo $tag->inputDateTime(
    [
        'name'  => 'born',
        'value' => '14-12-1980',
    ]
);
```

Volt syntax:
```php
{% raw %}{{ input_date_time(['name':'born', 'value':'14-12-1980']) }}{% endraw %}
```
   

```php
public function inputDateTimeLocal( string $name, array $parameters = [] ): string;
```
   Builds a HTML input[type='datetime-local'] tag
   
```php
use Phalcon\Html\Tag;

$tag = new Tag();

echo $tag->inputDateTimeLocal(
    [
        'name'  => 'born',
        'value' => '14-12-1980',
    ]
);
```

Volt syntax:
```php
{% raw %}{{ input_date_time_local(['name':'born', 'value':'14-12-1980']) }}{% endraw %}
```
   

```php
public function inputEmail( string $name, array $parameters = [] ): string;
```
Builds a HTML input[type='email'] tag

```php
use Phalcon\Html\Tag;

$tag = new Tag();

echo $tag->inputEmail(
    [
        'name' => 'email',
     ]
);
```

Volt syntax:
```php
{% raw %}{{ input_email(['name': 'email']);{% endraw %}
```


```php
public function inputFile( string $name, array $parameters = [] ): string;
```
Builds a HTML input[type='file'] tag

```php
use Phalcon\Html\Tag;

$tag = new Tag();

echo $tag->inputFile(
    [
        'name' => 'file',
     ]
);
```

Volt syntax:
```php
{% raw %}{{ input_file(['name': 'file']){% endraw %}
```


```php
public function inputHidden( string $name, array $parameters = [] ): string;
```
Builds a HTML input[type='hidden'] tag

```php
use Phalcon\Html\Tag;

$tag = new Tag();

echo $tag->inputHidden(
    [
        'name'  => 'my-field',
        'value' => 'mike',
    ]
);
```


```php
public function inputImage( string $name, array $parameters = [] ): string;
```
Builds a HTML input[type="image"] tag

```php
use Phalcon\Html\Tag;

$tag = new Tag();
echo $tag->inputImage(
    [
        'src' => '/img/button.png',
    ]
);
```

Volt syntax:
```php
{% raw %}{{ input_image(['src': '/img/button.png']) }}{% endraw %}
```


```php
public function inputMonth( string $name, array $parameters = [] ): string;
```
Builds a HTML input[type='month'] tag


```php
public function inputNumeric( string $name, array $parameters = [] ): string;
```
Builds a HTML input[type='number'] tag

```php
use Phalcon\Html\Tag;

$tag = new Tag();

echo $tag->numericField(
    [
        'name' => 'price',
        'min'  => '1',
        'max'  => '5',
    ]
);
```


```php
public function inputPassword( string $name, array $parameters = [] ): string;
```
Builds a HTML input[type='password'] tag

```php
use Phalcon\Html\Tag;

$tag = new Tag();

echo $tag->passwordField(
    [
        'name' => 'my-field',
        'size' => 30,
    ]
);
```


```php
public function inputRadio( string $name, array $parameters = [] ): string;
```
Builds a HTML input[type="radio"] tag

```php
use Phalcon\Html\Tag;

$tag = new Tag();

echo $tag->inputRadio(
    [
        'name'  => 'weather',
        'value" => 'hot',
    ]
);
```

Volt syntax:
```php
{% raw %}{{ input_radio(['name': 'weather', 'value": 'hot']) }}{% endraw %}
```


```php
public function inputRange( string $name, array $parameters = [] ): string;
```
   Builds a HTML input[type='range'] tag
   

```php
public function inputSearch( string $name, array $parameters = [] ): string;
```
Builds a HTML input[type='search'] tag


```php
public function inputTel( string $name, array $parameters = [] ): string;
```
   Builds a HTML input[type='tel'] tag
   

```php
public function inputText( string $name, array $parameters = [] ): string;
```
Builds a HTML input[type='text'] tag

```php
use Phalcon\Html\Tag;

$tag = new Tag();

echo $tag->inputText(
    [
        'name' => 'my-field',
        'size' => 30,
    ]
);
```


```php
public function inputTime( string $name, array $parameters = [] ): string;
```
Builds a HTML input[type='time'] tag


```php
public function inputUrl( string $name, array $parameters = [] ): string;
```
Builds a HTML input[type='url'] tag


```php
public function inputWeek( string $name, array $parameters = [] ): string;
```
Builds a HTML input[type='week'] tag


```php
public function javascript( string $url, array $parameters = [] ): string;
```
Builds a script[type="javascript"] tag

Parameters
`local` Local resource or not (default `true`)

```php
use Phalcon\Html\Tag;

$tag = new Tag();

echo $tag->javascript(
    'http://ajax.googleapis.com/ajax/libs/jquery/2.2.3/jquery.min.js',
       [
        'local' => false,
    ]
);

echo $tag->javascript('javascript/jquery.js');
```

Volt syntax:
```php
{% raw %}{{ javascript('http://ajax.googleapis.com/ajax/libs/jquery/2.2.3/jquery.min.js', ['local': false]) }}{% endraw %}
{% raw %}{{ javascript('javascript/jquery.js') }}{% endraw %}
```


```php
public function link( string $url, string $text = string, array $parameters = [] ): string;
```
Builds a HTML A tag using framework conventions

Parameters
`local` Local resource or not (default `true`)

```php
use Phalcon\Html\Tag;

$tag = new Tag();

echo $tag->link('signup/register', 'Register Here!');

echo $tag->link(
    'signup/register',
    'Register Here!',
    [
        'class' => 'btn-primary',
    ]
);

echo $tag->link(
    'https://phalcon.io/',
    'Phalcon!',
    [
        'local' => false,
    ]
);

echo $tag->link(
    'https://phalcon.io/',
    'Phalcon!',
    [
        'local'  => false,
        'target' => '_new',
    ]
);
```


```php
public function prependTitle( mixed $title ): Tag;
```
Prepends a text to current document title


```php
public function renderTitle( bool $prepend = bool, bool $append = bool ): string;
```
Renders the title with title tags. The title is automaticall escaped

```php
use Phalcon\Html\Tag;

$tag = new Tag();

$tag
       ->setTitleSeparator(' ')
        ->prependTitle(['Hello'])
        ->setTitle('World')
        ->appendTitle(['from Phalcon']);

echo $tag->renderTitle();             // <title>Hello World from Phalcon</title>
echo $tag->renderTitle(false);        // <title>World from Phalcon</title>
echo $tag->renderTitle(true, false);  // <title>Hello World</title>
echo $tag->renderTitle(false, false); // <title>World</title>
```

```php
{% raw %}{{ render_title() }}{% endraw %}
```


```php
public function reset( string $name, array $parameters = [] ): string;
```
Builds a HTML input[type="reset"] tag

```php
use Phalcon\Html\Tag;

$tag = new Tag();

echo $tag->reset('Reset')
```

Volt syntax:
```php
{% raw %}{{ reset('Save') }}{% endraw %}
```


```php
public function select( string $name, array $parameters = [], mixed $data = null ): string;
```
Builds a select element. It accepts an array or a resultset from
a Phalcon\Mvc\Model

```php
use Phalcon\Html\Tag;

$tag = new Tag();

echo $tag->select(
    'status',
    [
        'id'        => 'status-id',
        'useEmpty'  => true,
        'emptyValue => '',
        'emptyText' => 'Choose Status...',
    ],
    [
        'A' => 'Active',
        'I' => 'Inactive',
    ]
);

echo $tag->select(
    'status',
    [
        'id'        => 'status-id',
        'useEmpty'  => true,
        'emptyValue => '',
        'emptyText' => 'Choose Type...',
        'using'     => [
            'id,
            'name',
        ],
    ],
    Robots::find(
        [
            'conditions' => 'type = :type:',
            'bind'       => [
                'type' => 'mechanical',
            ]
        ]
    )
);
```


```php
public function setAttribute( string $name, mixed $value ): Tag;
```
Assigns default values to generated tags by helpers

```php
use Phalcon\Html\Tag;

$tag = new Tag();

// Assigning 'peter' to 'name' component
$tag->setAttribute('name', 'peter');

// Later in the view
echo $tag->inputText('name'); // Will have the value 'peter' by default
```


```php
public function setAttributes( array $values, bool $merge = bool ): Tag;
```
Assigns default values to generated tags by helpers

```php
use Phalcon\Html\Tag;

$tag = new Tag();

// Assigning 'peter' to 'name' component
$tag->setAttribute(
    [
        'name' => 'peter',
    ]
);

// Later in the view
echo $tag->inputText('name'); // Will have the value 'peter' by default
```


```php
public function setDocType( int $doctype ): Tag;
```
Set the document type of content


```php
public function setTitle( string $title ): Tag;
```
Set the title separator of view content

```php
use Phalcon\Html\Tag;

$tag = new Tag();

$tag->setTitle('Phalcon Framework');
```


```php
public function setTitleSeparator( string $separator ): Tag;
```
Set the title separator of view content

```php
use Phalcon\Html\Tag;

$tag = new Tag();

echo $tag->setTitleSeparator('-');
```


```php
public function stylesheet( string $url, array $parameters = [] ): string;
```
Builds a LINK[rel="stylesheet"] tag

Parameters
`local` Local resource or not (default `true`)

```php
use Phalcon\Html\Tag;

$tag = new Tag();

echo $tag->stylesheet(
    'http://fonts.googleapis.com/css?family=Rosario',
    [
        'local' => false,
    ]
);

echo $tag->stylesheet('css/style.css');
```

Volt syntax:
```php
{% raw %}{{ stylesheet('http://fonts.googleapis.com/css?family=Rosario', ['local': false]) }}{% endraw %}
{% raw %}{{ stylesheet('css/style.css') }}{% endraw %}
```


```php
public function submit( string $name, array $parameters = [] ): string;
```
Builds a HTML input[type="submit"] tag

```php
use Phalcon\Html\Tag;

$tag = new Tag();

echo $tag->submit('Save');
```

Volt syntax:
```php
{% raw %}{{ submit('Save') }}{% endraw %}
```


```php
public function textArea( string $name, array $parameters = [] ): string;
```
Builds a HTML TEXTAREA tag

```php
use Phalcon\Html\Tag;

$tag = new Tag();

echo $tag->textArea(
    'comments',
    [
        'cols' => 10,
        'rows' => 4,
    ]
);
```

Volt syntax:
```php
{% raw %}{{ text_area('comments', ['cols': 10, 'rows': 4]) }}{% endraw %}
```



        
<h1 id="html-tagfactory">Class Phalcon\Html\TagFactory</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/html/tagfactory.zep)

| Namespace  | Phalcon\Html |
| Uses       | Phalcon\Escaper, Phalcon\Escaper\EscaperInterface, Phalcon\Factory\AbstractFactory |
| Extends    | AbstractFactory |

ServiceLocator implementation for Tag helpers


## Properties
```php
/**
 * @var <EscaperInterface>
 */
private escaper;

```

## Methods
```php
public function __construct( EscaperInterface $escaper, array $services = [] );
```
TagFactory constructor.


```php
public function newInstance( string $name ): mixed;
```
@param string name

@return mixed
@throws Exception


```php
protected function getAdapters(): array;
```
//

