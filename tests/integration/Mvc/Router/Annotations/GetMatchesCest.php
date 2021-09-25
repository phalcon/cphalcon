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

namespace Phalcon\Tests\Integration\Mvc\Router\Annotations;

use IntegrationTester;

/**
 * Class GetMatchesCest
 */
class GetMatchesCest
{
    /**
     * Tests Phalcon\Mvc\Router\Annotations :: getMatches()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcRouterAnnotationsGetMatches(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Annotations - getMatches()');
        $I->skipTest('Need implementation');
    }
}
