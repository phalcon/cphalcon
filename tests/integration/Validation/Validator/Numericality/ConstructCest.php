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

namespace Phalcon\Test\Integration\Validation\Validator\Numericality;

use Phalcon\Test\Fixtures\Traits\ValidationTrait;
use Phalcon\Validation\Validator\Numericality;
use Phalcon\Validation\ValidatorInterface;
use IntegrationTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    use ValidationTrait;

    /**
     * Tests Phalcon\Validation\Validator\Numericality :: __construct()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function validationValidatorNumericalityConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\Numericality - __construct()');
        $validator = new Numericality();
        $this->checkConstruct($I, $validator);
    }
}
