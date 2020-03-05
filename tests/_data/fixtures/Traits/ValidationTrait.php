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

namespace Phalcon\Test\Fixtures\Traits;

use IntegrationTester;
use Phalcon\Validation\ValidatorInterface;

trait ValidationTrait
{
    /**
     * Tests Phalcon\Validation\Validator\* :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    private function checkConstruct(IntegrationTester $I, ValidatorInterface $validator)
    {
        $I->wantToTest(
            $this->getMessage($validator, '__construct()')
        );

        $I->assertInstanceOf(
            ValidatorInterface::class,
            $validator
        );
    }

    /**
     * Formats a message to be displayed in the tests
     */
    private function getMessage(ValidatorInterface $validator, string $method): string
    {
        $class = get_class($validator);

        return sprintf(
            str_replace('Phalcon\\', '', $class) . ' - %s',
            $method
        );
    }

    /**
     * Tests Phalcon\Validation\Validator\* :: getOption()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    private function checkGetOption(IntegrationTester $I, ValidatorInterface $validator)
    {
        $I->wantToTest(
            $this->getMessage(
                $validator,
                'getOption()'
            )
        );

        $validator->setOption('option', 'value');

        $I->assertEquals(
            'value',
            $validator->getOption('option')
        );
    }

    /**
     * Tests Phalcon\Validation\Validator\* :: hasOption()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    private function checkHasOption(IntegrationTester $I, ValidatorInterface $validator)
    {
        $I->wantToTest(
            $this->getMessage(
                $validator,
                'hasOption()'
            )
        );

        $I->assertFalse(
            $validator->hasOption('option')
        );
    }

    /**
     * Tests Phalcon\Validation\Validator\* :: setOption()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    private function checkSetOption(IntegrationTester $I, ValidatorInterface $validator)
    {
        $I->wantToTest(
            $this->getMessage(
                $validator,
                'setOption()'
            )
        );

        $validator->setOption('option', 'value');

        $I->assertEquals(
            'value',
            $validator->getOption('option')
        );
    }
}
