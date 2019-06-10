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

namespace Phalcon\Test\Unit\Html\Attributes;

use Phalcon\Html\Attributes;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class ConstructCest
{
    use DiTrait;

    /**
     * Unit Tests Phalcon\Html\Attributes :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function htmlAttributesConstruct(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - __construct()');

        $expected = [
            'class' => 'form-control',
            'name'  => 'q',
            'value' => '',
        ];

        $attributes = new Attributes($expected);

        $actual = $attributes->toArray();

        $I->assertSame($expected, $actual);

        // empty construct
        $expected = [];

        $attributes = new Attributes();

        $actual = $attributes->toArray();

        $I->assertSame($expected, $actual);
    }
}
