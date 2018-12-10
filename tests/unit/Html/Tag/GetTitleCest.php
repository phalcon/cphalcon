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
 * Class GetTitleCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class GetTitleCest
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
     * Tests Phalcon\Html\Tag :: getTitle()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTagGetTitle(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - getTitle()');
        $tag = new Tag();
        $tag->setDI($this->container);
        $value = "Hello Title";

        $tag->setTitle($value);
        $expected = 'Hello Title';
        $actual   = $tag->getTitle();
        $I->assertEquals($expected, $actual);
    }
    
    /**
     * Tests Phalcon\Html\Tag :: getTitle() - escape
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTagGetTitleEscape(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - getTitle() - escape');
        $tag = new Tag();
        $tag->setDI($this->container);
        $value = "Hello </title><script>alert('Got your nose!');</script><title>";

        $tag->setTitle($value);
        $expected = 'Hello &lt;/title&gt;&lt;script&gt;alert(&#039;'
            . 'Got your nose!&#039;);&lt;/script&gt;&lt;title&gt;';
        $actual   = $tag->getTitle();
        $I->assertEquals($expected, $actual);
    }
}
