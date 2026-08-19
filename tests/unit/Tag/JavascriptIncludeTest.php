<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Tag;

use Phalcon\Tag;

use const PHP_EOL;

/**
 * Covers the doctype-dependent `type` attribute of Tag::javascriptInclude().
 *
 * HTML5 made `type="text/javascript"` the default for a SCRIPT tag, so the
 * attribute is only added for the older doctypes. The `local` channels are
 * characterized in LocalParameterTest.
 */
final class JavascriptIncludeTest extends AbstractTagTestCase
{
    public function testJavascriptIncludeKeepsAnExplicitType(): void
    {
        Tag::setDocType(Tag::HTML401_STRICT);

        $this->assertSame(
            '<script type="module" src="https://phalcon.io/js/app.js">'
            . '</script>' . PHP_EOL,
            Tag::javascriptInclude(['js/app.js', 'type' => 'module'])
        );
    }

    public function testJavascriptIncludeWithHtml5OmitsTheType(): void
    {
        $this->assertSame(
            '<script src="https://phalcon.io/js/app.js"></script>' . PHP_EOL,
            Tag::javascriptInclude('js/app.js')
        );
    }

    public function testJavascriptIncludeWithOlderDocTypeAddsTheType(): void
    {
        Tag::setDocType(Tag::HTML401_STRICT);

        $this->assertSame(
            '<script type="text/javascript" src="https://phalcon.io/js/app.js">'
            . '</script>' . PHP_EOL,
            Tag::javascriptInclude('js/app.js')
        );
    }
}
