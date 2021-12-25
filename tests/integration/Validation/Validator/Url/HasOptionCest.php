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

namespace Phalcon\Tests\Integration\Validation\Validator\Url;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\ValidationTrait;
use Phalcon\Filter\Validation\Validator\Url;

/**
 * Class HasOptionCest
 */
class HasOptionCest
{
    use ValidationTrait;

    /**
     * Tests Phalcon\Filter\Validation\Validator\Url :: hasOption()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function filterValidationValidatorUrlHasOption(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\Url - hasOption()');

        $validator = new Url(
            [
                'message' => 'This is a message',
            ]
        );

        $this->checkHasOption($I, $validator);
    }
}
