<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

if (!function_exists('phalcon_prepare_virtual_path')) {
function phalcon_prepare_virtual_path($path, $separator) {
	$virtual_str = '';

	if (!is_string($path) || !is_string($separator)) {
		if (is_string($path)) {
			return $path;
		} else {
			return "";
		}
	}

	for ($i = 0; $i < strlen($path); $i++) {
		$ch = $path[$i];
		if ($ch == '\0') {
			break;
		}
		if ($ch == '/' || $ch == '\\' || $ch == ':') {
			$virtual_str .= $separator;
		} else {
			$virtual_str .= strtolower($ch);
		}
	}

	return $virtual_str;
}
}

class ViewEnginesMarkdownTest extends PHPUnit_Framework_TestCase
{

	public function testMarkdownParserBasics()
	{

		$markdown = new \Phalcon\Mvc\View\Engine\Markdown\Compiler();

		$intermediate = $markdown->parse('');
		$this->assertEmpty($intermediate);

		//Paragraphs, Headers, Blockquotes
		$text = <<<EOT
A First Level Header
====================

A Second Level Header
---------------------

Now is the time for all good men to come to
the aid of their country. This is just a
regular paragraph.

The quick brown fox jumped over the lazy
dog's back.

### Header 3

> This is a blockquote.
> 
> This is the second paragraph in the blockquote.
>
> ## This is an H2 in a blockquote
EOT;
		$html = <<<EOT
<h1>A First Level Header</h1>

<h2>A Second Level Header</h2>

<p>Now is the time for all good men to come to
the aid of their country. This is just a
regular paragraph.</p>

<p>The quick brown fox jumped over the lazy
dog&#39;s back.</p>

<h3>Header 3</h3>

<blockquote>
<p>This is a blockquote.</p>

<p>This is the second paragraph in the blockquote.</p>

<h2>This is an H2 in a blockquote</h2>
</blockquote>
EOT;

		$intermediate = $markdown->parse($text);
		$this->assertEquals($intermediate, $html . "\n");

		//Phrase Emphasis
		$text = <<<EOT
Some of these words *are emphasized*.
Some of these words _are emphasized also_.

Use two asterisks for **strong emphasis**.
Or, if you prefer, __use two underscores instead__.
EOT;
		$html = <<<EOT
<p>Some of these words <em>are emphasized</em>.
Some of these words <em>are emphasized also</em>.</p>

<p>Use two asterisks for <strong>strong emphasis</strong>.
Or, if you prefer, <strong>use two underscores instead</strong>.</p>
EOT;

		$intermediate = $markdown->parse($text);
		$this->assertEquals($intermediate, $html . "\n");

		//Lists
		$text = <<<EOT
* Candy.
* Gum.
* Booze.
EOT;
		$html = <<<EOT
<ul>
<li>Candy.</li>
<li>Gum.</li>
<li>Booze.</li>
</ul>
EOT;
		$intermediate = $markdown->parse($text);
		$this->assertEquals($intermediate, $html . "\n");

		$text = <<<EOT
+ Candy.
+ Gum.
+ Booze.
EOT;
		$intermediate = $markdown->parse($text);
		$this->assertEquals($intermediate, $html . "\n");

		$text = <<<EOT
- Candy.
- Gum.
- Booze.
EOT;
		$intermediate = $markdown->parse($text);
		$this->assertEquals($intermediate, $html . "\n");

		$text = <<<EOT
1. Red
2. Green
3. Blue
EOT;
		$html = <<<EOT
<ol>
<li>Red</li>
<li>Green</li>
<li>Blue</li>
</ol>
EOT;
		$intermediate = $markdown->parse($text);
		$this->assertEquals($intermediate, $html . "\n");

		$text = <<<EOT
* A list item.

  With multiple paragraphs.

* Another item in the list.
EOT;
		$html = <<<EOT
<ul>
<li><p>A list item.</p>

<p>With multiple paragraphs.</p></li>
<li><p>Another item in the list.</p></li>
</ul>
EOT;
		$intermediate = $markdown->parse($text);
		$this->assertEquals($intermediate, $html . "\n");

		//Links
		$text = "This is an [example link](http://example.com/).";
		$html = '<p>This is an <a href="http://example.com/">example link</a>.</p>';
		$intermediate = $markdown->parse($text);
		$this->assertEquals($intermediate, $html . "\n");

		//Optionally, you may include a title attribute in the parentheses:
		$text = 'This is an [example link](http://example.com/ "With a Title").';
		$html = '<p>This is an <a href="http://example.com/" title="With a Title">example link</a>.</p>';
		$intermediate = $markdown->parse($text);
		$this->assertEquals($intermediate, $html . "\n");

		//Reference-style links
		$text = <<<EOT
I get 10 times more traffic from [Google][1] than from
[Yahoo][2] or [MSN][3].

[1]: http://google.com/ "Google"
[2]: http://search.yahoo.com/ "Yahoo Search"
[3]: http://search.msn.com/ "MSN Search"
EOT;
		$html = <<<EOT
<p>I get 10 times more traffic from <a href="http://google.com/" title="Google">Google</a> than from
<a href="http://search.yahoo.com/" title="Yahoo Search">Yahoo</a> or <a href="http://search.msn.com/" title="MSN Search">MSN</a>.</p>
EOT;
		$intermediate = $markdown->parse($text);
		$this->assertEquals($intermediate, $html . "\n");

		//The title attribute is optional.
		$text = <<<EOT
I start my morning with a cup of coffee and
[The New York Times][NY Times].

[ny times]: http://www.nytimes.com/
EOT;
		$html = <<<EOT
<p>I start my morning with a cup of coffee and
<a href="http://www.nytimes.com/">The New York Times</a>.</p>
EOT;
		$intermediate = $markdown->parse($text);
		$this->assertEquals($intermediate, $html . "\n");

		//Images
		$text = '![alt text](/path/to/img.jpg "Title")';
		$html = '<p><img src="/path/to/img.jpg" alt="alt text" title="Title"></p>';
		$intermediate = $markdown->parse($text);
		$this->assertEquals($intermediate, $html . "\n");

		$text = <<<EOT
![alt text][id]

[id]: /path/to/img.jpg "Title"
EOT;
		$intermediate = $markdown->parse($text);
		$this->assertEquals($intermediate, $html . "\n");

		//Code
		$text = <<<EOT
I strongly recommend against using any `<blink>` tags.

I wish SmartyPants used named entities like `&mdash;` instead of decimal-encoded entites like `&#8212;`.
EOT;
		$html = <<<EOT
<p>I strongly recommend against using any <code>&lt;blink&gt;</code> tags.</p>

<p>I wish SmartyPants used named entities like <code>&amp;mdash;</code> instead of decimal-encoded entites like <code>&amp;#8212;</code>.</p>
EOT;
		$intermediate = $markdown->parse($text);
		$this->assertEquals($intermediate, $html . "\n");

		$text = <<<EOT
If you want your page to validate under XHTML 1.0 Strict, you've got to put paragraph tags in your blockquotes:

    <blockquote>
    <p>For example.</p>
    </blockquote>
EOT;
		$html = <<<EOT
<p>If you want your page to validate under XHTML 1.0 Strict, you&#39;ve got to put paragraph tags in your blockquotes:</p>

<pre><code>&lt;blockquote&gt;
&lt;p&gt;For example.&lt;/p&gt;
&lt;/blockquote&gt;
</code></pre>
EOT;
		$intermediate = $markdown->parse($text);
		$this->assertEquals($intermediate, $html . "\n");
	}

	public function testMarkdownCompilerFile()
	{
		@unlink('unit-tests/views/test18/index.md.php');

		$markdown = new \Phalcon\Mvc\View\Engine\Markdown\Compiler();

		//Simple file
		$markdown->compileFile('unit-tests/views/test18/index.md', 'unit-tests/views/test18/index.md.php');

		$compilation = file_get_contents('unit-tests/views/test18/index.md.php');
		$html = <<<EOT
<h1>Header 1</h1>

<h2>header 2</h2>

<ul>
<li>a</li>
<li>b</li>
</ul>

<h1>Extend</h1>

<p><strong>tables</strong></p>

<table>
<thead>
<tr>
<th>a</th>
<th>b</th>
<th>c</th>
</tr>
</thead>

<tbody>
<tr>
<td>A</td>
<td>B</td>
<td>C</td>
</tr>
<tr>
<td>D</td>
<td>E</td>
<td>F</td>
</tr>
</tbody>
</table>

<p><strong>fenced-code</strong></p>

<pre><code>code block
</code></pre>

<p><strong>autolink</strong></p>

<p><a href="http://www.google.co.jp">http://www.google.co.jp</a></p>

<p><strong>task</strong></p>

<ul>
<li><input type="checkbox"> a</li>
<li><input checked="" type="checkbox"> b</li>
</ul>
EOT;
		$this->assertEquals($compilation, $html . "\n");
	}

	public function testMarkdownEngine()
	{
		@unlink('unit-tests/views/test18/index.md.php');

		$di = new Phalcon\DI();

		$view = new Phalcon\Mvc\View();
		$view->setDI($di);
		$view->setViewsDir('unit-tests/views/');

		$view->registerEngines(array(
			'.md' => 'Phalcon\Mvc\View\Engine\Markdown'
		));

		$view->start();
		$view->render('test18', 'index');
		$view->finish();

		$html = <<<EOT
<h1>Header 1</h1>

<h2>header 2</h2>

<ul>
<li>a</li>
<li>b</li>
</ul>

<h1>Extend</h1>

<p><strong>tables</strong></p>

<table>
<thead>
<tr>
<th>a</th>
<th>b</th>
<th>c</th>
</tr>
</thead>

<tbody>
<tr>
<td>A</td>
<td>B</td>
<td>C</td>
</tr>
<tr>
<td>D</td>
<td>E</td>
<td>F</td>
</tr>
</tbody>
</table>

<p><strong>fenced-code</strong></p>

<pre><code>code block
</code></pre>

<p><strong>autolink</strong></p>

<p><a href="http://www.google.co.jp">http://www.google.co.jp</a></p>

<p><strong>task</strong></p>

<ul>
<li><input type="checkbox"> a</li>
<li><input checked="" type="checkbox"> b</li>
</ul>
EOT;
		$this->assertEquals($view->getContent(), $html . "\n");
	}
}
