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

namespace Phalcon\Tests\Integration\Validation\Validator\StringLength;

use IntegrationTester;

class GetTemplatesCest
{
    /**
     * Tests Phalcon\Filter\Validation\Validator\StringLength :: getTemplates()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function filterValidationValidatorStringLengthGetTemplates(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength - getTemplates()');

        $I->skipTest('Need implementation');
    }
}
