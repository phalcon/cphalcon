<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Html\Tag;

use Phalcon\Html\Tag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

/**
 * Class TitleRenderCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class TitleRenderCest
{
    use DiTrait;

    /**
     * @param UnitTester $I
     */
    public function _before(UnitTester $I)
    {
        $this->newDi();
        $this->setDiEscaper();
    }

    /**
     * Tests Phalcon\Html\Tag :: titleRender()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTagTitleRender(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - titleRender()');
        $tag   = new Tag();
        $container = $this->getDi();
        $tag->setDI($container);
        $value = "Hello </title><script>alert('Got your nose!');</script><title>";

        $tag->titleSet($value);
        $expected = '<title>Hello &lt;/title&gt;&lt;script&gt;alert(&#039;'
            . 'Got your nose!&#039;);&lt;/script&gt;&lt;title&gt;</title>' . PHP_EOL;
        $actual   = $tag->titleRender();
        $I->assertEquals($expected, $actual);
    }
}
