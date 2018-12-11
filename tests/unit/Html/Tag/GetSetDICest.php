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

use Phalcon\Di;
use Phalcon\Html\Tag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

/**
 * Class GetSetDICest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class GetSetDICest
{
    use DiTrait;

    /**
     * Tests Phalcon\Html\Tag :: getDI()/setDI()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTagGetSetDI(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - getDI()/setDI()');
        $tag = new Tag();
        $this->newDi();
        $tag->setDI($this->container);

        $class  = Di::class;
        $actual = $tag->getDI();
        $I->assertInstanceOf($class, $actual);
    }
}
