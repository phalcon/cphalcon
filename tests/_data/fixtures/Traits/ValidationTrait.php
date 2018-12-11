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

namespace Phalcon\Test\Fixtures\Traits;

use IntegrationTester;
use Phalcon\Validation\ValidatorInterface;

/**
 * Trait ValidationTrait
 *
 * @package Phalcon\Test\Fixtures\Traits
 */
trait ValidationTrait
{
    /**
     * Tests Phalcon\Validation\Validator\* :: __construct()
     *
     * @param IntegrationTester  $I
     * @param ValidatorInterface $validator
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    private function checkConstruct(IntegrationTester $I, ValidatorInterface $validator)
    {
        $I->wantToTest($this->getMessage($validator, '__construct()'));
        $I->assertInstanceOf(ValidatorInterface::class, $validator);
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

    /**
     * Tests Phalcon\Validation\Validator\* :: getOption()
     *
     * @param IntegrationTester  $I
     * @param ValidatorInterface $validator
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    private function checkGetOption(IntegrationTester $I, ValidatorInterface $validator)
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
     * @param IntegrationTester  $I
     * @param ValidatorInterface $validator
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    private function checkHasOption(IntegrationTester $I, ValidatorInterface $validator)
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
     * @param IntegrationTester  $I
     * @param ValidatorInterface $validator
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    private function checkSetOption(IntegrationTester $I, ValidatorInterface $validator)
    {
        $I->wantToTest($this->getMessage($validator, 'setOption()'));
        $validator->setOption('option', 'value');

        $expected = 'value';
        $actual   = $validator->getOption('option');
        $I->assertEquals($expected, $actual);
    }
}
