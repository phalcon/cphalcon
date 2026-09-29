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

namespace Phalcon\Tests\Benchmarks\Apps\Mvc\Controllers;

use Phalcon\Mvc\Controller;
use Phalcon\Tests\Benchmarks\Apps\Mvc\Fixture;

final class ProductsController extends Controller
{
    public function showAction(string $id): void
    {
        $this->view->setVars((new Fixture())->productVars($id));
    }
}
