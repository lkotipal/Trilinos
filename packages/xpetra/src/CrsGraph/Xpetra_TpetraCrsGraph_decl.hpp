// @HEADER
//
// ***********************************************************************
//
//             Xpetra: A linear algebra interface package
//                  Copyright 2012 Sandia Corporation
//
// Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
// the U.S. Government retains certain rights in this software.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact
//                    Jonathan Hu       (jhu@sandia.gov)
//                    Andrey Prokopenko (aprokop@sandia.gov)
//                    Ray Tuminaro      (rstumin@sandia.gov)
//
// ***********************************************************************
//
// @HEADER
#ifndef XPETRA_TPETRACRSGRAPH_DECL_HPP
#define XPETRA_TPETRACRSGRAPH_DECL_HPP

/* this file is automatically generated - do not edit (see script/tpetra.py) */

#include "Xpetra_TpetraConfigDefs.hpp"
#include "Xpetra_Exceptions.hpp"

#include "Tpetra_CrsGraph.hpp"

#include "Xpetra_CrsGraph.hpp"
#include "Xpetra_TpetraMap_decl.hpp"
#include "Xpetra_TpetraImport_decl.hpp"
#include "Xpetra_TpetraExport_decl.hpp"
#include "Xpetra_Utils.hpp"

namespace Xpetra {

template <class LocalOrdinal,
          class GlobalOrdinal,
          class Node = Tpetra::KokkosClassic::DefaultNode::DefaultNodeType>
class TpetraCrsGraph
  : public CrsGraph<LocalOrdinal, GlobalOrdinal, Node> {
#undef XPETRA_TPETRACRSGRAPH_SHORT
#include "Xpetra_UseShortNamesOrdinal.hpp"
  // The following typedef is used by the XPETRA_DYNAMIC_CAST() macro.
  typedef TpetraCrsGraph<LocalOrdinal, GlobalOrdinal, Node> TpetraCrsGraphClass;
  typedef TpetraImport<LocalOrdinal, GlobalOrdinal, Node> TpetraImportClass;
  typedef TpetraExport<LocalOrdinal, GlobalOrdinal, Node> TpetraExportClass;
  typedef Map map_type;

  typedef typename Xpetra::CrsGraph<LocalOrdinal, GlobalOrdinal, Node>::local_graph_type local_graph_type;

 public:
  //! @name Constructor/Destructor Methods
  //@{

  //! Constructor specifying fixed number of entries for each row.
  TpetraCrsGraph(const RCP<const Map>& rowMap, size_t maxNumEntriesPerRow, const RCP<ParameterList>& params = null);

  //! Constructor specifying (possibly different) number of entries in each row.
  TpetraCrsGraph(const RCP<const Map>& rowMap, const ArrayRCP<const size_t>& NumEntriesPerRowToAlloc, const RCP<ParameterList>& params = null);

  //! Constructor specifying column Map and fixed number of entries for each row.
  TpetraCrsGraph(const RCP<const Map>& rowMap, const RCP<const Map>& colMap, size_t maxNumEntriesPerRow, const RCP<ParameterList>& params = null);

  //! Constructor specifying column Map and number of entries in each row.
  TpetraCrsGraph(const RCP<const Map>& rowMap, const RCP<const Map>& colMap, const ArrayRCP<const size_t>& NumEntriesPerRowToAlloc, const RCP<ParameterList>& params = null);

  // Constructor for fused import
  TpetraCrsGraph(const RCP<const CrsGraph>& sourceGraph,
                 const Import& importer,
                 const RCP<const Map>& domainMap           = Teuchos::null,
                 const RCP<const Map>& rangeMap            = Teuchos::null,
                 const RCP<Teuchos::ParameterList>& params = Teuchos::null);

  /// \brief Constructor specifying column Map and arrays containing the graph in sorted, local ids.
  ///
  ///
  /// \param rowMap [in] Distribution of rows of the graph.
  ///
  /// \param colMap [in] Distribution of columns of the graph.
  ///
  /// \param rowPointers [in] The beginning of each row in the graph,
  ///   as in a CSR "rowptr" array.  The length of this vector should be
  ///   equal to the number of rows in the graph, plus one.  This last
  ///   entry should store the nunber of nonzeros in the graph.
  ///
  /// \param columnIndices [in] The local indices of the columns,
  ///   as in a CSR "colind" array.  The length of this vector
  ///   should be equal to the number of unknowns in the graph.
  ///
  /// \param params [in/out] Optional list of parameters.  If not
  ///   null, any missing parameters will be filled in with their
  ///   default values.
  TpetraCrsGraph(const Teuchos::RCP<const Map>& rowMap,
                 const Teuchos::RCP<const Map>& colMap,
                 const typename local_graph_type::row_map_type& rowPointers,
                 const typename local_graph_type::entries_type::non_const_type& columnIndices,
                 const Teuchos::RCP<Teuchos::ParameterList>& plist = Teuchos::null);

  /// \brief Constructor specifying column, domain and range maps, and a
  ///   local (sorted) graph, which the resulting CrsGraph views.
  ///
  /// Unlike most other CrsGraph constructors, successful completion
  /// of this constructor will result in a fill-complete graph.
  ///
  /// \param rowMap [in] Distribution of rows of the graph.
  ///
  /// \param colMap [in] Distribution of columns of the graph.
  ///
  /// \param domainMap [in] The graph's domain Map. MUST be one to
  ///   one!
  ///
  /// \param rangeMap [in] The graph's range Map.  MUST be one to
  ///   one!  May be, but need not be, the same as the domain Map.
  ///
  /// \param lclGraph [in] A locally indexed Kokkos::StaticCrsGraph
  ///   whose local row indices come from the specified row Map, and
  ///   whose local column indices come from the specified column
  ///   Map.
  ///
  /// \param params [in/out] Optional list of parameters.  If not
  ///   null, any missing parameters will be filled in with their
  ///   default values.
  TpetraCrsGraph(const local_graph_type& lclGraph,
                 const Teuchos::RCP<const map_type>& rowMap,
                 const Teuchos::RCP<const map_type>& colMap,
                 const Teuchos::RCP<const map_type>& domainMap      = Teuchos::null,
                 const Teuchos::RCP<const map_type>& rangeMap       = Teuchos::null,
                 const Teuchos::RCP<Teuchos::ParameterList>& params = Teuchos::null);

  /// \brief Constructor specifying column Map and a local (sorted)
  ///   graph, which the resulting CrsGraph views.
  ///
  /// Unlike most other CrsGraph constructors, successful completion
  /// of this constructor will result in a fill-complete graph.
  ///
  /// \param rowMap [in] Distribution of rows of the graph.
  ///
  /// \param colMap [in] Distribution of columns of the graph.
  ///
  /// \param lclGraph [in] A locally indexed Kokkos::StaticCrsGraph
  ///   whose local row indices come from the specified row Map, and
  ///   whose local column indices come from the specified column
  ///   Map.
  ///
  /// \param params [in/out] Optional list of parameters.  If not
  ///   null, any missing parameters will be filled in with their
  ///   default values.
  TpetraCrsGraph(const Teuchos::RCP<const Map>& rowMap,
                 const Teuchos::RCP<const Map>& colMap,
                 const local_graph_type& lclGraph,
                 const Teuchos::RCP<Teuchos::ParameterList>& params);

  TpetraCrsGraph(const Teuchos::RCP<const Map>& rowMap,
                 const Teuchos::RCP<const Map>& colMap,
                 const Teuchos::ArrayRCP<size_t>& rowPointers,
                 const Teuchos::ArrayRCP<LocalOrdinal>& columnIndices,
                 const Teuchos::RCP<Teuchos::ParameterList>& params = Teuchos::null);

  //! Destructor.
  virtual ~TpetraCrsGraph();

  //! @name Insertion/Removal Methods
  //@{

  //! Insert global indices into the graph.
  void insertGlobalIndices(GlobalOrdinal globalRow, const ArrayView<const GlobalOrdinal>& indices);

  //! Insert local indices into the graph.
  void insertLocalIndices(const LocalOrdinal localRow, const ArrayView<const LocalOrdinal>& indices);

  //! Remove all graph indices from the specified local row.
  void removeLocalIndices(LocalOrdinal localRow);

  //! Allocates the 1D pointer arrays of the graph
  void allocateAllIndices(size_t numNonZeros, ArrayRCP<size_t>& rowptr, ArrayRCP<LocalOrdinal>& colind);

  //! Sets the 1D pointer arrays of the graph.
  void setAllIndices(const ArrayRCP<size_t>& rowptr, const ArrayRCP<LocalOrdinal>& colind);

  //! Gets the 1D pointer arrays of the graph.
  void getAllIndices(ArrayRCP<const size_t>& rowptr, ArrayRCP<const LocalOrdinal>& colind) const;

  //@}

  //! @name Transformational Methods
  //@{

  //! Signal that data entry is complete, specifying domain and range maps.
  void fillComplete(const RCP<const Map>& domainMap, const RCP<const Map>& rangeMap, const RCP<ParameterList>& params = null);

  //! Signal that data entry is complete.
  void fillComplete(const RCP<ParameterList>& params = null);

  //! Expert version of fillComplete
  void
  expertStaticFillComplete(const Teuchos::RCP<const map_type>& domainMap,
                           const Teuchos::RCP<const map_type>& rangeMap,
                           const Teuchos::RCP<const Import>& importer =
                               Teuchos::null,
                           const Teuchos::RCP<const Export>& exporter =
                               Teuchos::null,
                           const Teuchos::RCP<Teuchos::ParameterList>& params =
                               Teuchos::null);
  //@}

  //@}

  //! @name Methods implementing RowGraph.
  //@{

  //! Returns the communicator.
  RCP<const Comm<int> > getComm() const;

  //! Returns the Map that describes the row distribution in this graph.
  RCP<const Map> getRowMap() const;

  //! Returns the Map that describes the column distribution in this graph.
  RCP<const Map> getColMap() const;

  //! Returns the Map associated with the domain of this graph.
  RCP<const Map> getDomainMap() const;

  //! Returns the Map associated with the domain of this graph.
  RCP<const Map> getRangeMap() const;

  //! Returns the importer associated with this graph.
  RCP<const Import> getImporter() const;

  //! Returns the exporter associated with this graph.
  RCP<const Export> getExporter() const;

  //! Returns the number of global rows in the graph.
  global_size_t getGlobalNumRows() const;

  //! Returns the number of global columns in the graph.
  global_size_t getGlobalNumCols() const;

  //! Returns the number of graph rows owned on the calling node.
  size_t getLocalNumRows() const;

  //! Returns the number of columns connected to the locally owned rows of this graph.
  size_t getLocalNumCols() const;

  //! Returns the index base for global indices for this graph.
  GlobalOrdinal getIndexBase() const;

  //! Returns the global number of entries in the graph.
  global_size_t getGlobalNumEntries() const;

  //! Returns the local number of entries in the graph.
  size_t getLocalNumEntries() const;

  //! Returns the current number of entries on this node in the specified global row.
  size_t getNumEntriesInGlobalRow(GlobalOrdinal globalRow) const;

  //! Returns the current number of entries on this node in the specified local row.
  size_t getNumEntriesInLocalRow(LocalOrdinal localRow) const;

  //! Returns the current number of allocated entries for this node in the specified global row .
  size_t getNumAllocatedEntriesInGlobalRow(GlobalOrdinal globalRow) const;

  //! Returns the current number of allocated entries on this node in the specified local row.
  size_t getNumAllocatedEntriesInLocalRow(LocalOrdinal localRow) const;

  //! Maximum number of entries in all rows over all processes.
  size_t getGlobalMaxNumRowEntries() const;

  //! Maximum number of entries in all rows owned by the calling process.
  size_t getLocalMaxNumRowEntries() const;

  //! Whether the graph has a column Map.
  bool hasColMap() const;

  //! Whether column indices are stored using local indices on the calling process.
  bool isLocallyIndexed() const;

  //! Whether column indices are stored using global indices on the calling process.
  bool isGloballyIndexed() const;

  //! Whether fillComplete() has been called and the graph is in compute mode.
  bool isFillComplete() const;

  //! Returns true if storage has been optimized.
  bool isStorageOptimized() const;

  //! Return a const, nonpersisting view of global indices in the given row.
  void getGlobalRowView(GlobalOrdinal GlobalRow, ArrayView<const GlobalOrdinal>& Indices) const;

  //! Return a const, nonpersisting view of local indices in the given row.
  void getLocalRowView(LocalOrdinal LocalRow, ArrayView<const LocalOrdinal>& indices) const;

  /// \brief Access the local KokkosSparse::StaticCrsGraph data for host use
  typename local_graph_type::HostMirror getLocalGraphHost() const;

  /// \brief Access the local KokkosSparse::StaticCrsGraph data for device use
  local_graph_type getLocalGraphDevice() const;

  //! Force the computation of global constants if we don't have them
  void computeGlobalConstants();

  //@}

  //! @name Overridden from Teuchos::Describable
  //@{

  //! Return a simple one-line description of this object.
  std::string description() const;

  //! Print the object with some verbosity level to an FancyOStream object.
  void describe(Teuchos::FancyOStream& out, const Teuchos::EVerbosityLevel verbLevel = Teuchos::Describable::verbLevel_default) const;

  //@}

  //! @name Advanced methods, at increased risk of deprecation.
  //@{

  //! Get an ArrayRCP of the row-offsets.
  ArrayRCP<const size_t> getNodeRowPtrs() const;

  //@}

  //! Implements DistObject interface
  //{@

  //! Access function for the Tpetra::Map this DistObject was constructed with.
  Teuchos::RCP<const Map> getMap() const;

  //! Import.
  void doImport(const DistObject<GlobalOrdinal, LocalOrdinal, GlobalOrdinal, Node>& source,
                const Import& importer, CombineMode CM);

  //! Export.
  void doExport(const DistObject<GlobalOrdinal, LocalOrdinal, GlobalOrdinal, Node>& dest,
                const Import& importer, CombineMode CM);

  //! Import (using an Exporter).
  void doImport(const DistObject<GlobalOrdinal, LocalOrdinal, GlobalOrdinal, Node>& source,
                const Export& exporter, CombineMode CM);

  //! Export (using an Importer).
  void doExport(const DistObject<GlobalOrdinal, LocalOrdinal, GlobalOrdinal, Node>& dest,
                const Export& exporter, CombineMode CM);

  // @}

  //! @name Xpetra specific
  //@{

  //! TpetraCrsGraph constructor to wrap a Tpetra::CrsGraph object
  TpetraCrsGraph(const Teuchos::RCP<Tpetra::CrsGraph<LocalOrdinal, GlobalOrdinal, Node> >& graph);

  //! Get the underlying Tpetra graph
  RCP<const Tpetra::CrsGraph<LocalOrdinal, GlobalOrdinal, Node> > getTpetra_CrsGraph() const;

  //@}

 private:
  RCP<Tpetra::CrsGraph<LocalOrdinal, GlobalOrdinal, Node> > graph_;
};  // TpetraCrsGraph class

// TODO: move that elsewhere
template <class LocalOrdinal, class GlobalOrdinal, class Node>
RCP<const CrsGraph<LocalOrdinal, GlobalOrdinal, Node> >
toXpetra(RCP<const Tpetra::CrsGraph<LocalOrdinal, GlobalOrdinal, Node> > graph) {  // TODO: return TpetraCrsGraph instead of CrsGraph
  // typedef TpetraCrsGraph<LocalOrdinal, GlobalOrdinal, Node> TpetraCrsGraphClass;
  // XPETRA_RCP_DYNAMIC_CAST(const TpetraCrsGraphClass, graph, tGraph, "toTpetra");
  if (graph.is_null()) {
    return Teuchos::null;
  }
  RCP<Tpetra::CrsGraph<LocalOrdinal, GlobalOrdinal, Node> > tGraph =
      Teuchos::rcp_const_cast<Tpetra::CrsGraph<LocalOrdinal, GlobalOrdinal, Node> >(graph);
  return rcp(new Xpetra::TpetraCrsGraph<LocalOrdinal, GlobalOrdinal, Node>(tGraph));
}

template <class LocalOrdinal, class GlobalOrdinal, class Node>
RCP<const Tpetra::CrsGraph<LocalOrdinal, GlobalOrdinal, Node> >
toTpetra(const RCP<const CrsGraph<LocalOrdinal, GlobalOrdinal, Node> >& graph) {
  typedef TpetraCrsGraph<LocalOrdinal, GlobalOrdinal, Node> TpetraCrsGraphClass;
  XPETRA_RCP_DYNAMIC_CAST(const TpetraCrsGraphClass, graph, tpetraCrsGraph, "toTpetra");
  return tpetraCrsGraph->getTpetra_CrsGraph();
}

}  // namespace Xpetra

#endif  // XPETRA_TPETRACRSGRAPH_DECL_HPP
