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

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Di;
use Phalcon\Tag;

use UnitTester;

class SetDICest
{
    /**
     * Tests Phalcon\Tag :: getDI() / setDI()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-07
     */
    public function tagGetSetDI(UnitTester $I)
    {
        $I->wantToTest('Tag - getDI() / setDI()');

        $container = new Di();

        $tag = new Tag();

        $tag->setDI($container);

        $I->assertSame(
            $container,
            $tag->getDI()
        );

        $class  = Di::class;
        $actual = $tag->getDI();
        $I->assertInstanceOf($class, $actual);

        $expected = $container;
        $I->assertEquals($expected, $actual);
    }
}
