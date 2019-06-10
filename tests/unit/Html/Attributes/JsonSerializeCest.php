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

class JsonSerializeCest
{
    use DiTrait;

    /**
     * Unit Tests Phalcon\Html\Attributes :: jsonSerialize()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function htmlAttributesJsonSerialize(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - jsonSerialize()');

        $expected = [
            'class' => 'form-control',
            'name'  => 'q',
            'value' => '',
        ];

        // serialize with json
        $attributes = new Attributes($expected);

        $actual = $attributes->jsonSerialize();

        $I->assertSame($expected, $actual);
    }
}
