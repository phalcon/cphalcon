<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Controllers;

class ProductsController
{
    /**
     * @Get("/products")
     */
    public function indexAction()
    {
    }

    /**
     * @Get("/products/edit/{id:[0-9]+}", name="edit-product")
     * @param int $id
     */
    public function editAction($id)
    {
    }

    /**
     * @Route("/products/save", methods={"POST", "PUT"}, name="save-product")
     */
    public function saveAction()
    {
    }
}
