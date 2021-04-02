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

namespace Phalcon\Test\Integration\Validation\Validator\StringLength;

use IntegrationTester;

class MessageFactoryCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength :: messageFactory()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthMessageFactory(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength - messageFactory()');

        $I->skipTest('Need implementation');
    }
}
