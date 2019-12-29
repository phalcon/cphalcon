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

namespace Phalcon\Test\Integration\Mvc\Router\Annotations;

use IntegrationTester;

/**
 * Class AddPostCest
 */
class AddPostCest
{
    /**
     * Tests Phalcon\Mvc\Router\Annotations :: addPost()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcRouterAnnotationsAddPost(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Annotations - addPost()');
        $I->skipTest('Need implementation');
    }
}
