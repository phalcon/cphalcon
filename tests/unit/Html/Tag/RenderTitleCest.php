<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Html\Tag;

use Phalcon\Html\Tag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\TagSetupTrait;
use UnitTester;

class RenderTitleCest
{
    use DiTrait;
    use TagSetupTrait;

    /**
     * Tests Phalcon\Html\Tag :: renderTitle()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function htmlTagRenderTitle(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - renderTitle()');
        $tag = new Tag();
        $tag->setDI($this->container);
        $value = "Hello </title><script>alert('Got your nose!');</script><title>";

        $tag->setTitle($value);
        $expected = '<title>Hello &lt;/title&gt;&lt;script&gt;alert(&#039;'
            . 'Got your nose!&#039;);&lt;/script&gt;&lt;title&gt;</title>' . PHP_EOL;
        $actual   = $tag->renderTitle();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: renderTitle() - parameters
     *
     * @since 2018-12-27
     */
    public function htmlTagRenderTitleParameters(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - renderTitle() - parameters');
        $tag = new Tag();
        $tag->setDI($this->container);
        $tag->setTitleSeparator(' ');

        $tag->prependTitle(['Hello'])
            ->setTitle('World')
            ->appendTitle(['from Phalcon'])
        ;

        $expected = '<title>Hello World from Phalcon</title>' . PHP_EOL;
        $actual   = $tag->renderTitle();
        $I->assertEquals($expected, $actual);

        $expected = '<title>World from Phalcon</title>' . PHP_EOL;
        $actual   = $tag->renderTitle(false);
        $I->assertEquals($expected, $actual);

        $expected = '<title>Hello World</title>' . PHP_EOL;
        $actual   = $tag->renderTitle(true, false);
        $I->assertEquals($expected, $actual);

        $expected = '<title>World</title>' . PHP_EOL;
        $actual   = $tag->renderTitle(false, false);
        $I->assertEquals($expected, $actual);
    }
}
