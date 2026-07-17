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

namespace Phalcon\Tests\Support\Controllers;

use Phalcon\Annotations\Router\Get;
use Phalcon\Annotations\Router\Route;
use Phalcon\Annotations\Router\RoutePrefix;

/**
 * @RoutePrefix("/robots")
 */
#[RoutePrefix("/robots")]
class RobotsController
{
    /**
     * @Get("/")
     */
    #[Get("/")]
    public function indexAction()
    {
    }

    /**
     * @Get("/edit/{id:[0-9]+}", name="edit-robot")
     * @param int $id
     */
    #[Get("/edit/{id:[0-9]+}", name: "edit-robot")]
    public function editAction($id)
    {
    }

    /**
     * @Route("/save", methods={"POST", "PUT"}, name="save-robot")
     */
    #[Route("/save", methods: ["POST", "PUT"], name: "save-robot")]
    public function saveAction()
    {
    }
}
