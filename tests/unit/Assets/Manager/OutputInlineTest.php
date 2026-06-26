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

namespace Phalcon\Tests\Unit\Assets\Manager;

use Phalcon\Assets\Manager;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Assets\Fake\UppercaseFilter;

use const PHP_EOL;

final class OutputInlineTest extends AbstractUnitTestCase
{
    /**
     * Characterization test: `outputInline()` applies the collection filters
     * unconditionally, ignoring the per-code `filter` flag. An inline code
     * added with `filter: false` is still filtered. This pins the current
     * (drifted) behavior ahead of the v7 fix that will honor
     * `Inline::getFilter()`.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-23
     */
    public function testAssetsManagerOutputInlineCharacterizationFilterFlagIgnored(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));
        $manager->useImplicitOutput(false);
        $manager->addInlineCss('p { color: red; }', false);

        $collection = $manager->getCss();
        $collection->addFilter(new UppercaseFilter());

        // Despite filter: false, the content is uppercased by the filter
        $expected = '<style type="text/css">P { COLOR: RED; }</style>' . PHP_EOL;
        $actual   = $manager->outputInline($collection, 'style');
        $this->assertSame($expected, $actual);
    }

    /**
     * Characterization test: in join mode the single joined `<style>`/`<script>`
     * element is rendered with whatever attributes the LAST code in the loop
     * carried; the earlier codes' attributes are discarded. This pins the
     * current positional behavior ahead of the v7 fix that will render the
     * joined element with the collection's attributes.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-23
     */
    public function testAssetsManagerOutputInlineCharacterizationJoinedAttributesUseLastCode(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));
        $manager->useImplicitOutput(false);

        $collection = $manager->getCss();
        $collection->addInlineCss('a{color:red}', true, ['data-id' => 'first']);
        $collection->addInlineCss('b{color:blue}', true, ['data-id' => 'second']);
        $collection->join(true);

        // Joined element uses the last code's attributes ('second'); 'first' is lost
        $expected = '<style data-id="second">a{color:red}b{color:blue}</style>' . PHP_EOL;
        $actual   = $manager->outputInline($collection, 'style');
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAssetsManagerOutputInlineCss(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));
        $css     = 'p { color: #000099 }';

        $manager->addInlineCss($css);
        $manager->useImplicitOutput(false);

        $collection = $manager->getCss();

        $expected = "<style type=\"text/css\">{$css}</style>" . PHP_EOL;
        $actual   = $manager->outputInline($collection, 'style');
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAssetsManagerOutputInlineJs(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));
        $js      = 'alert("Hello world");';

        $manager->addInlineJs($js);
        $manager->useImplicitOutput(false);

        $collection = $manager->getJs();

        $expected = "<script type=\"application/javascript\">{$js}</script>" . PHP_EOL;
        $actual   = $manager->outputInline($collection, 'script');
        $this->assertSame($expected, $actual);
    }
}
