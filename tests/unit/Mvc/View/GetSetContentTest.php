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
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\ViewTrait;

class GetSetContentTest extends AbstractUnitTestCase
{
    use ViewTrait;

    /**
     * Tests Phalcon\Mvc\View :: getContent() / setContent()
     */
    public function testMvcViewGetSetContent(): void
    {
        $view = new View();

        $view->setContent('<h1>hello</h1>');

        $this->assertEquals(
            '<h1>hello</h1>',
            $view->getContent()
        );
    }
}
