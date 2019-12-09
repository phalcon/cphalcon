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

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;

class JsonSerializeCest
{
    /**
     * Tests Phalcon\Mvc\Model :: jsonSerialize()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelJsonSerialize(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - jsonSerialize()');

        $I->skipTest('Need implementation');
    }
}
