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

use function array_flip;
use function uniqid;

class GetSetAttributesCest
{
    /**
     * Tests Phalcon\Forms\Element\Select :: getAttributes()/setAttributes()
     *
     * @param IntegrationTester $I
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-12-05
     */
    public function formsElementSelectGetSetAttributes(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Select - getAttributes()/setAttributes()');

        $name    = uniqid();
        $data    = [
            'one'   => 'two',
            'three' => 'four',
        ];
        $flipped = array_flip($data);

        $object = new Select($name);

        $actual = $object->getAttributes();
        $I->assertEmpty($actual);

        $object = new Select($name, null, $data);

        $expected = $data;
        $actual   = $object->getAttributes();
        $I->assertSame($expected, $actual);

        $object->setAttributes($flipped);

        $expected = $flipped;
        $actual   = $object->getAttributes();
        $I->assertSame($expected, $actual);
    }
}
