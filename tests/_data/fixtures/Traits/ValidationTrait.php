<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits;

use Phalcon\Validation\ValidatorInterface;
use UnitTester;

trait ValidationTrait
{
    private function validatorGetOption(UnitTester $I, ValidatorInterface $validator)
    {
        $validator->setOption('option', 'value');

        $expected = 'value';
        $actual   = $validator->getOption('option');
        $I->assertEquals($expected, $actual);
    }

    private function validatorHasOption(UnitTester $I, ValidatorInterface $validator)
    {
        $actual = $validator->hasOption('option');
        $I->assertFalse($actual);

        $actual = $validator->hasOption('message');
        $I->assertTrue($actual);
    }

    private function validatorSetOption(UnitTester $I, ValidatorInterface $validator)
    {
        $validator->setOption('option', 'value');

        $expected = 'value';
        $actual   = $validator->getOption('option');
        $I->assertEquals($expected, $actual);
    }
}
