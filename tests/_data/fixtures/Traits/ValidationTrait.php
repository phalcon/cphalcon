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
    /**
     * Tests Phalcon\Validation\Validator\* :: __construct()
     *
     * @param UnitTester         $I
     * @param ValidatorInterface $validator
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    private function checkConstruct(UnitTester $I, ValidatorInterface $validator)
    {
        $I->wantToTest($this->getMessage($validator, '__construct()'));
        $I->assertInstanceOf(ValidatorInterface::class, $validator);
    }

    /**
     * Tests Phalcon\Validation\Validator\* :: getOption()
     *
     * @param UnitTester         $I
     * @param ValidatorInterface $validator
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    private function checkGetOption(UnitTester $I, ValidatorInterface $validator)
    {
        $I->wantToTest($this->getMessage($validator, 'getOption()'));
        $validator->setOption('option', 'value');

        $expected = 'value';
        $actual   = $validator->getOption('option');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Validation\Validator\* :: hasOption()
     *
     * @param UnitTester         $I
     * @param ValidatorInterface $validator
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    private function checkHasOption(UnitTester $I, ValidatorInterface $validator)
    {
        $I->wantToTest($this->getMessage($validator, 'hasOption()'));
        $actual = $validator->hasOption('option');
        $I->assertFalse($actual);

        $actual = $validator->hasOption('message');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Validation\Validator\* :: setOption()
     *
     * @param UnitTester         $I
     * @param ValidatorInterface $validator
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    private function checkSetOption(UnitTester $I, ValidatorInterface $validator)
    {
        $I->wantToTest($this->getMessage($validator, 'setOption()'));
        $validator->setOption('option', 'value');

        $expected = 'value';
        $actual   = $validator->getOption('option');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Formats a message to be displayed in the tests
     *
     * @param ValidatorInterface $validator
     * @param string             $method
     *
     * @return string
     */
    private function getMessage(ValidatorInterface $validator, string $method): string
    {
        $class = get_class($validator);

        return sprintf(str_replace('Phalcon\\', '', $class) . ' - %s', $method);
    }
}
