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

namespace Phalcon\Tests\Integration\Validation\Validator\Alnum;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\ValidationTrait;
use Phalcon\Filter\Validation\Validator\Alnum;

class ConstructCest
{
    use ValidationTrait;

    /**
     * Tests Phalcon\Filter\Validation\Validator\Alnum :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function filterValidationValidatorAlnumConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\Alnum - __construct()');

        $validator = new Alnum();

        $this->checkConstruct($I, $validator);
    }
}
