<?php

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
