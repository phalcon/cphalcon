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

namespace Phalcon\Tests\Unit\Mvc\View;

use Phalcon\Mvc\View;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\ViewTrait;

class UnderscoreIssetTest extends AbstractUnitTestCase
{
    use ViewTrait;

    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function testMvcViewUnderscoreIsset(): void
    {
        $view = new View();

        $view->paramA = '1';

        $view->setVar('paramB', '2');

        $this->assertTrue(
            isset($view->paramA)
        );

        $this->assertTrue(
            isset($view->paramA)
        );

        $this->assertFalse(
            isset($view->paramC)
        );
    }
}
