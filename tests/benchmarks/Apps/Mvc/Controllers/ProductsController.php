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

final class ProductsController extends Controller
{
    public function showAction(string $id): void
    {
        $items = [];
        for ($index = 1; $index <= 10; $index++) {
            $items[] = [
                'name'  => 'Item <' . $index . '> & "more"',
                'price' => $index * 10,
            ];
        }

        $this->view->setVars(
            [
                'id'    => (int) $id,
                'items' => $items,
                'name'  => 'Product <b>' . $id . '</b> & "friends"',
                'title' => 'Product ' . $id,
            ]
        );
    }
}
