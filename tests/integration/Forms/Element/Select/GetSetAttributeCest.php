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

namespace Phalcon\Tests\Integration\Forms\Element\Select;

use IntegrationTester;
use Phalcon\Forms\Element\Select;

use function uniqid;

class GetSetAttributeCest
{
    /**
     * Tests Phalcon\Forms\Element\Select :: getAttribute()/setAttribute()
     *
     * @param IntegrationTester $I
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-12-05
     */
    public function formsElementSelectGetSetAttribute(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Select - getAttribute()/setAttribute()');

        $name = uniqid();
        $data = [
            'one'   => 'two',
            'three' => 'four',
        ];

        $object = new Select($name);

        $expected = 'fallback';
        $actual   = $object->getAttribute('one', 'fallback');
        $I->assertSame($expected, $actual);

        $object = new Select($name, null, $data);

        $expected = 'two';
        $actual   = $object->getAttribute('one', 'fallback');
        $I->assertSame($expected, $actual);

        $object->setAttribute('one', 'four');

        $expected = 'four';
        $actual   = $object->getAttribute('one', 'fallback');
        $I->assertSame($expected, $actual);
    }
}
