<?php
/**
 * @file
 * nasascience_customization_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function nasascience_customization_feature_taxonomy_default_vocabularies() {
  return array(
    'page_template' => array(
      'name' => 'Page Template',
      'machine_name' => 'page_template',
      'description' => 'Pages for various sections have slight variations in the look and feel. The image in the top navbar changes for each section, e.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'science_missions_directorate_vocabulary' => array(
      'name' => 'Science Mission Directorate',
      'machine_name' => 'science_missions_directorate_vocabulary',
      'description' => 'Vocabulary of taxonomy terms for SMD web sites',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
